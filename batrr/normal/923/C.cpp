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
#define Bystro ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;                    
const ll maxn=3e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
ll n,a[maxn],ans[maxn];
set<ll > st;
map< ll , ll > cnt;
int gcnt(ll l , ll r){
	if(st.lower_bound(l)==st.lower_bound(r+1))
		return 0;
	return 1;
}
int main(){      
	//stdi
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%I64d",&x);
		cnt[x]++;
		st.insert(x);
	}
	st.insert( 1e18 );
	for(int i=1;i<=n;i++){
		ll L=0, R= (1ll<<32)-1,j=32,val=a[i];
		while(L!=R){
			j--;
			ll M=(L+R)/2;  
			int a=gcnt(L,M);
			int b=gcnt(M+1,R);
			//cout<<L<<" "<<R<<" "<<( 1ll << j )<<" "<<a<<" "<<b<<endl;
			if(a==0){
		    	L=M+1;
		    	continue;
		    }
		    if(b==0){
		    	R=M;
		    	continue;
		    }
		    if( ( val&( 1ll << j ) ) !=0)
		    	L=M+1;
		    else
		    	R=M;
		   
		}
		
		ans[i]=a[i]^L;
		cnt[L]--;
		if(cnt[L]==0)
			st.erase(L);
	}
	for(int i=1;i<=n;i++)
		printf("%I64d ",ans[i]);
}