//following:a whole piece of shit.
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
const int inv10=ksm(10);
int n,m,pos[400100],cnt,lp[1200100],rp[1200100],tp[1200100];//0:bracket 1:plus 2:times.
int ten[400100],net[400100];
char s[400100];
vector<int>v[1200100];
vector<int>pre[1200100],zer[1200100];
stack<int>stk;
void dfs(int x){
	if(tp[x]==0)pre[x].push_back(0);
	if(tp[x]==1)pre[x].push_back(1);
	for(auto y:v[x]){
		dfs(y);
		if(tp[x]==0)pre[x].push_back((pre[x].back()+(zer[y].empty()?pre[y].back():0))%mod);
		if(tp[x]==1){
			if(pre[y].back()==0)zer[x].push_back(pre[x].size()),pre[x].push_back(pre[x].back());
			else pre[x].push_back(1ll*pre[x].back()*pre[y].back()%mod);
		}
	}
	if(tp[x]==2){
		if(!v[x].empty())pre[x].push_back(pre[v[x].back()].back());
		else{
			pre[x].push_back(0);
			for(int i=lp[x];i<=rp[x];i++)pre[x].push_back((10ll*pre[x].back()+s[i]-'0')%mod);
		}
	}
}
#define all(x) x.begin(),x.end()
int calc(int x,int l,int r){
	if(!v[x].empty())return pre[x].back();
	return (pre[x][r-lp[x]+1]+mod-1ll*pre[x][l-lp[x]]*ten[r-l+1]%mod)%mod;
}
int CALC(int x,int l,int r){
//	printf("%d %d\n",l,r);
//	for(auto i:zer[x])printf("%d ",i);puts("");
//	printf("%d %d\n",r,pre[x].size());
	auto it=upper_bound(all(zer[x]),l);
	if(it!=zer[x].end()&&*it<=r)return 0;
	if(!r)return 1;
	if(l==v[x].size()+1)return 1;
//	printf("[%d,%d]<%d,%d>\n",l,r,pre[x][r],pre[x][l+1]);
	return 1ll*pre[x][r]*ksm(pre[x][l+1])%mod;
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	ten[0]=net[0]=1;for(int i=1;i<=n;i++)ten[i]=10ll*ten[i-1]%mod,net[i]=1ll*inv10*net[i-1]%mod;
	s[0]='(',s[n+1]=')';
	for(int i=0;i<=n+1;i++){
		if(s[i]=='(')stk.push(++cnt),lp[cnt]=i,tp[cnt]=0;
		pos[i]=stk.top();
		if(s[i]==')')rp[stk.top()]=i,stk.pop();
	}
	for(int i=0;i<=n+1;i++){
//		printf("%d:%d %c\n",i,stk.size(),s[i]);
		if(s[i]=='('){
			if(!stk.empty())v[stk.top()].push_back(pos[i]);
			stk.push(pos[i]);
			tp[++cnt]=1,lp[cnt]=i+1,stk.push(cnt);
			tp[++cnt]=2,lp[cnt]=i+1,stk.push(cnt);
		}
		if(s[i]=='+'){
			int tms=stk.top();stk.pop();
			rp[tms]=i-1;
			int pls=stk.top();stk.pop();
			rp[pls]=i-1;
			int bra=stk.top();
			v[pls].push_back(tms);
			v[bra].push_back(pls);
			tp[++cnt]=1,lp[cnt]=i+1,stk.push(cnt);
			tp[++cnt]=2,lp[cnt]=i+1,stk.push(cnt);
		}
		if(s[i]=='*'){
			int tms=stk.top();stk.pop();
			rp[tms]=i-1;
			int pls=stk.top();
			v[pls].push_back(tms);
			tp[++cnt]=2,lp[cnt]=i+1,stk.push(cnt);
		}
		if(s[i]==')'){
			int tms=stk.top();stk.pop();
			rp[tms]=i-1;
			int pls=stk.top();stk.pop();
			rp[pls]=i-1;
			int bra=stk.top();stk.pop();
			v[pls].push_back(tms);
			v[bra].push_back(pls);
		}
	}
//	for(int i=1;i<=n;i++)printf("%d ",pos[i]);puts("");
	dfs(1);
/*	for(int i=1;i<=cnt;i++){
		printf("%d(%d)[%d,%d]<%d,%d>",i,tp[i],lp[i],rp[i],pre[i].back(),zer[i].empty());
		for(auto j:v[i])printf("%d ",j);puts("");
	}*/
	scanf("%d",&m);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
//		for(int x=l;x<=r;x++)putchar(s[x]);puts("");
		if(pos[l-1]!=pos[r+1]||s[l]=='+'||s[l]=='*'||s[r]=='+'||s[r]=='*'){puts("-1");continue;}
		int x=pos[l-1];
		lp[0]=l;
		int p=upper_bound(all(v[x]),0,[](int a,int b){return lp[a]<lp[b];})-v[x].begin()-1;
		int P=v[x][p];
		int _p=upper_bound(all(v[P]),0,[](int a,int b){return lp[a]<lp[b];})-v[P].begin()-1;
		int _P=v[P][_p];
		rp[0]=r;
		int q=lower_bound(all(v[x]),0,[](int a,int b){return rp[a]<rp[b];})-v[x].begin();
		int Q=v[x][q];
		int _q=lower_bound(all(v[Q]),0,[](int a,int b){return rp[a]<rp[b];})-v[Q].begin();
		int _Q=v[Q][_q];
//		printf("X%dp%dP%d_p%d_P%dq%dQ%d_q%d_Q%d\n",x,p,P,_p,_P,q,Q,_q,_Q);
		if(p==q&&_p==_q){printf("%d\n",calc(_P,l,r));continue;}
		int pp=calc(_P,l,rp[_P]);
		int qq=calc(_Q,lp[_Q],r);
//		printf("[%d %d]\n",pp,qq);
		if(p==q){printf("%d\n",1ll*pp*CALC(P,_p,_q)%mod*qq%mod);continue;}
		pp=1ll*pp*CALC(P,_p,v[P].size())%mod;
		qq=1ll*qq*CALC(Q,-1,_q)%mod;
//		printf("[%d %d]\n",pp,qq);
		printf("%d\n",(0ll+pp+(pre[x][q]+mod-pre[x][p+1])%mod+qq)%mod);
	}
	return 0;
}