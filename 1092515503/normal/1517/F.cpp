/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int inv2=499122177;
void ADD(int&x,int y){if((x+=y)>=mod)x-=mod;}
int n,R,res;
map<int,int>f[310],g;
vector<int>v[310];
void dfs(int x,int fa){
	f[x].clear();
	f[x][-1]=f[x][R]=1;
	for(auto y:v[x])if(y!=fa){
		dfs(y,x);
		for(auto i:f[x])for(auto j:f[y]){
			int val=1ll*i.second*j.second%mod;
			if(i.first>=0&&j.first>=0){ADD(g[max(i.first,j.first-1)],val);continue;}
			if(i.first<0&&j.first<0){ADD(g[min(i.first,j.first-1)],val);continue;}
			if(i.first<0){
				if(j.first>=-i.first){ADD(g[j.first-1],val);continue;}
				else{ADD(g[i.first],val);continue;}
			}
			if(j.first<0){
				if(i.first>=-j.first){ADD(g[i.first],val);continue;}
				else{ADD(g[j.first-1],val);continue;}
			}
		}
		f[x]=g,g.clear();
	}
	// printf("%d:",x);
	// for(auto i:f[x])printf("[%d,%d]",i.first,i.second);puts("");
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(R=1;R<n;R++){
		// printf("%d:\n",R);
		dfs(1,0);
		for(auto x:f[1])if(x.first>=0)(res+=x.second)%=mod;
	}
	// printf("%d\n",res);
	for(int i=1;i<=n;i++)res=1ll*res*inv2%mod;
	printf("%d\n",(n-1+mod-res)%mod);
	return 0;
}