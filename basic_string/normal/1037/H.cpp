#include<bits/stdc++.h>
using namespace std;
const int N=5200099,M=2e5+9;
string s,x[M];
vector<int>v[M],vc[M*2],ans[M*2],L[M/2],R[M/2],f,he,ne,tr,lp,rp,pos;
queue<int>qu;
struct P{
	unsigned char c1,c2,c3;
	bool emp(){return!(c1||c2||c3);}
};
struct T{P c[26];};
vector<T>t;
int pti(const P&x){return(x.c1<<16)|(x.c2<<8)|x.c3;}
P itp(int x){P a;a.c1=x>>16,a.c2=x>>8,a.c3=x;return a;}
int dfn;
void dfs(int x){
	lp[x]=++dfn;
	for(int i=he[x];i;i=ne[i])dfs(i);
	rp[x]=dfn;
}
void add(int x){for(;x<=dfn;x+=x&-x)++tr[x];}
int sum(int x){int r=0;for(;x;x-=x&-x)r+=tr[x];return r;}
int get(int x){return sum(rp[x])-sum(lp[x]-1);}
int main(){
	int q,i,l,r,o,j,k,now,y,z,ct=0,id=0;////
	ios::sync_with_stdio(0),cin>>s>>q,t.resize(N);
	for(i=1;i<=q;++i){
		cin>>l>>r>>x[i],o=x[i].size(),k=min(o,r-l),x[i]+='a'-1,v[i].resize(k+1);
		for(j=now=0;j<=k;++j){
			if(j){
				if(t[now].c[y].emp())t[now].c[y]=itp(++id);
				now=pti(t[now].c[y]);
			}
			v[i][j]=++ct,L[l+j-1].push_back(ct),R[r].push_back(ct),y=x[i][j]-'a',vc[ct].resize(26-y-1);
			for(z=y+1;z<26;++z){
				if(t[now].c[z].emp())t[now].c[z]=itp(++id);
				vc[ct][z-y-1]=pti(t[now].c[z]);
			}
		}
	}
	for(i=0;i<26;++i)if(!t[0].c[i].emp())qu.push(pti(t[0].c[i]));
	for(f.resize(id+2);qu.size();){
		i=qu.front(),qu.pop(),k=f[i];
		for(j=0;j<26;++j)if(t[i].c[j].emp())t[i].c[j]=t[k].c[j];
		else y=pti(t[i].c[j]),f[y]=pti(t[k].c[j]),qu.push(y);
	}
	for(o=s.size(),pos.resize(o+2),i=now=0;i<o;++i)now=pti(t[now].c[s[i]-'a']),pos[i+1]=now;
	t={},t.shrink_to_fit(),he.resize(id+2),ne=tr=lp=rp=he;
	for(i=1;i<=id;++i)ne[i]=he[f[i]],he[f[i]]=i;
	for(i=1;i<=ct;++i)ans[i].resize(vc[i].size());
	for(i=1,dfs(0);i<=o;++i){
		add(lp[pos[i]]);
		for(int j:L[i])for(y=vc[j].size(),k=0;k<y;++k)ans[j][k]=get(vc[j][k]);
		for(int j:R[i])for(y=vc[j].size(),k=0;k<y;++k)ans[j][k]-=get(vc[j][k]);
	}
	for(i=1;i<=q;++i){
		for(j=v[i].size()-1;~j;--j)for(k=v[i][j],z=vc[k].size(),y=0;y<z;++y)if(ans[k][y]){
			for(o=0;o<j;++o)cout<<x[i][o];
			cout<<char(x[i][j]+y+1)<<'\n';
			goto gg;
		}
		cout<<"-1\n";
		gg:;
	}
	return 0;
}