#include<cstdio>
#include<vector>
#include<cstring>
#define S 1
#define N 200100
#define Q 1000000007
using namespace std;
const int c[S]={40666888};
int hs[S][26][N],ht[S][26],slen,tlen,tp[26];
int sz[26],f[26];
char s[N],t[N];
int qp(int a,int p){
	int r=1,x=a;
	while(p){
		if(p&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		p>>=1;
	}
	return r;
}
void build(){
	for(char x='a';x<='z';x++){
		for(int i=0;i<S;i++){
			hs[i][x-'a'][0]=ht[i][x-'a']=0;
			int m=1;
			for(int j=1;j<=slen;j++){
				if(s[j]==x) hs[i][x-'a'][j]=(hs[i][x-'a'][j-1]+m)%Q;
				else hs[i][x-'a'][j]=hs[i][x-'a'][j-1];
				m=1LL*c[i]*m%Q;
			}
			m=1;
			for(int j=1;j<=tlen;j++){
				if(t[j]==x) ht[i][x-'a']+=m;
				m=1LL*c[i]*m%Q;
				if(ht[i][x-'a']>=Q) ht[i][x-'a']-=Q;
			}
		}
	}
}
inline bool check(int p,int r,int sc,int tc){
	if(1LL*r*(hs[0][sc][p+tlen-1]+Q-hs[0][sc][p-1])%Q!=ht[0][tc]){
		return false;
	}
	return true;
}
int main(){
	int to[26],r;
	bool used[26];
	vector<int> ans;
	scanf("%d%d",&slen,&tlen);
	scanf("%s%s",s+1,t+1);
	build();
	for(int i=1;i<=tlen;i++){
		tp[t[i]-'a']=i;
	}
	for(int i=1;i<=slen-tlen+1;i++){
		r=qp(c[0],Q-i);
		memset(to,-1,sizeof(to));
		memset(used,0,sizeof(used));
		bool flag=true;
		for(int j=0;j<26;j++){
			if(tp[j]){
				if(check(i,r,s[tp[j]+i-1]-'a',j)){
					to[j]=s[tp[j]+i-1]-'a';
				}
				else{
					flag=false;
				}
			}
		}
		if(!flag) continue;
		for(int j=0;j<26;j++){
			if(to[j]==-1) continue;
			if(used[to[j]]||to[to[j]]!=-1&&to[to[j]]!=j) flag=false;
			used[to[j]]=true;
		}
		if(flag) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		if(i) printf(" %d",ans[i]);
		else printf("%d",ans[i]);
	}
	putchar('\n');
}