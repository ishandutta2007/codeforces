#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
 
#include <cstring>
#include <string>
#include <cmath>    
#include <algorithm>
 
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>                                                      
#include <stack>
#include <list>
#include <deque>                                              
 
#include <ctime>
#include <cassert> 
 
#define nm "C" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ld long double                                                                                                             	
#define ll long long                                                                                                            
#define ull unsigned long long 
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0);

using namespace std;                    
const ll maxn=1e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e17,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
ll n,a[maxn],suf[maxn],pre[maxn],mx[maxn],ans;
map<ll,ll>cnt;
set<ll>st;
void add(ll x){
	cnt[x]++;
	st.insert(x);
}
void del(ll x){
	cnt[x]--;
	if(cnt[x]==0)	
		st.erase(x);
}
bool get(ll l, ll r){
	return st.lower_bound(l)!=st.lower_bound(r+1);
}
int main(){
	Bystro              
	cin>>n;         
	
	for(int i=1;i<=n;i++)
		cin>>a[i];

	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]^a[i]; 
	
	for(int i=n;i>=1;i--)
		suf[i]=suf[i+1]^a[i];

	for(int i=n+1;i>=1;i--)
		add(suf[i]);
	
	for(int i=0;i<=n;i++){
		if(i!=0)
			del(suf[i]);
		ll l=0,r= (1ll<<42)-1;
		for(int j=41;j>=0;j--){
			ll m=(l+r)/2;
			bool a=get(l,m),b=get(m+1,r);

			if(a && b){
				if( pre[i] & ( 1ll << j) )
					r=m;
				else
					l=m+1;
			}else{
				if(a)
					r=m;
				else
					l=m+1;
			}
		}	
		
		ans=max(pre[i]^l,ans);
	}
	cout<<ans<<endl;
}