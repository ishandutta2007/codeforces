// Tima the best
#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
                       
#define ll long long   
#define ull unsigned long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e4+123,inf=1e9;
int n,q;
pair< ll ,ll > dp[maxn],mod=mp(1e9+7,1e15+2e7+3e5+4);
vector<int> v,add[maxn],del[maxn];
bitset<maxn>ans;
void addd( pair< ll ,ll > &a, pair < ll , ll > b) {
	a.f+=b.f;
	if(a.f>mod.f)
		a.f-=mod.f;
    
    a.s+=b.s;
	if(a.s>mod.s)
		a.s-=mod.s;
}
void dell( pair< ll ,ll > &a, pair < ll , ll > b) {
	a.f-=b.f;
	if(a.f<0)
		a.f+=mod.f;
    
    a.s-=b.s;
	if(a.s<0)
		a.s+=mod.s;
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	//#else
	//	freopen ("headmasters.in", "r", stdin);
	//	freopen ("headmasters.out", "w", stdout);
    #endif                          
	scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
        add[l].pb(x);
		del[r+1].pb(x);
	}
	dp[0]=mp(1,1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<add[i].size();j++){
			int x=add[i][j];
			for(int q=maxn;q>=0;q--)
				if(q+x<maxn)
					addd(dp[q+x],dp[q]);
		}
	    for(int j=0;j<del[i].size();j++){
			int x=del[i][j];
			for(int q=0;q<maxn;q++)
				if(q+x<maxn)
                    dell(dp[q+x],dp[q]);
		}
	    
		for(int q=1;q<=n;q++)
			if( dp[q].f !=0 && dp[q].s!=0 )
				ans[q]=1;
			
	}
	for(int i=1;i<=n;i++)
		if( ans[i] )
			v.pb(i);     

    printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
}