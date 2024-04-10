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
typedef unsigned long long ull;
typedef long long ll;
mt19937_64 rnd(19260817);
int n,m,p;
ull b[500100];
vector<int>v;
unordered_map<ull,int>mp;
vector<int>u[100100];
struct dat{
	int a[6],w;
	friend bool operator<(const dat&u,const dat&v){return u.w<v.w;}
}d[100100];
int A[3200100],B[3200100],tp[3200100],mn=0x7f7f7f7f;
ll tot;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++)scanf("%d",&d[i].a[j]),v.push_back(d[i].a[j]);
		sort(d[i].a,d[i].a+m);
		scanf("%d",&d[i].w);
	}
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)d[i].a[j]=lower_bound(v.begin(),v.end(),d[i].a[j])-v.begin();
	for(int i=0;i<v.size();i++)b[i]=rnd();
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++)for(int j=0;j<(1<<m);j++){
		ull w=0;
		for(int k=0;k<m;k++)if(j&(1<<k))w^=b[d[i].a[k]];
		if(mp.find(w)!=mp.end())u[i].push_back(mp[w]);
		else u[i].push_back(mp[w]=++p),tp[p]=__builtin_popcount(j)&1;
	}
	// for(int i=1;i<=n;i++){printf("%d:",d[i].w);for(auto x:u[i])printf("%d ",x);puts("");}
	for(int i=1;i<=n;i++)for(auto x:u[i])B[x]++;
	for(int i=1,j=n;i<=n;i++){
		for(auto x:u[i])tot+=B[x]*(tp[x]?-1:1),A[x]++;
		while(tot){
			for(auto x:u[j])tot-=A[x]*(tp[x]?-1:1),B[x]--;
			if(!tot){for(auto x:u[j])tot+=A[x]*(tp[x]?-1:1),B[x]++;break;}
			j--;
		}
		// printf("<%d,%d>\n",i,j);
		if(tot)mn=min(mn,d[i].w+d[j].w);
	}
	if(mn==0x7f7f7f7f)puts("-1");else printf("%d\n",mn);
	return 0;
}