#include <bits/stdc++.h>
 
#define nm "" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                                                                                                            
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e6+123,mod=1e9+7,N=2e6+123;
ll x,d,n,a[maxn],cur;
int main(){                
	cin>>x>>d;
	for(ll i=30;i>=1;i--){
		ll m=(1ll<<i)-1;
		while( m <= x ){
			x-=m;    
			for(int j=1;j<=i;j++)
				a[++n]=cur;
			cur+=d+1;
		}
	}
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]+1<<" ";
}