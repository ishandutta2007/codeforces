#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6+123,inf=1e9+123,LOG=18,block=450,mod=1e9+7,N=1e7+12;
unsigned ll ld[N],x,n,cnt[N],up[N];
vector<int>p;
unsigned ll get(ll x,ll p){    
	ll res=0;
	while(x)
		res+=(x/=p);
	return res;
}
bool check(ll x){
	for(int i=0;i<p.size();i++)
		if( cnt[p[i]] > get(x,p[i]) )
			return 0;
	return 1;
}
int main(){
    #ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif
	for(int i=2;i<N;i+=2)
		ld[i]=2;
	for(int i=3;i<N;i+=2)
		if(ld[i]==0){
			ld[i]=i;
			if( 1ll*i*i<N )
				for(int j=i*i;j<N;j+=i+i)
					ld[j]=i;
		}
	for(int i=2;i<N;i++)
		if(ld[i]==i)
			p.pb(i);
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%d",&x);
    	up[x+1]--;
	}
	for(int i=1;i<N;i++){
		n+=up[i];
		x=i;
		while(x>1)
			cnt[ld[x]]+=n,x/=ld[x];
	}
	ll l=1,r=1e13;
	while(l<=r){
		ll m=(l+r)/2;
		if( !check(m) )
			l=m+1;
		else
			r=m-1;
	}
	cout<<l;
}