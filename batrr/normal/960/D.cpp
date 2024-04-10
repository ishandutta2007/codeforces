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
const ll maxn=1e5+123,N=2e6+123;
ll q,a[62],p[62];
ll get(ll x){
	for(int i=61;i>=0;i--)
		if( (1ll<<i) & x)
			return i;    
}
void solve(ll x, ll lvl){
	cout<<x<<" ";
	if(x==1)
		return;
	x= ( x+a[lvl] )%p[lvl]+p[lvl];
	x/=2;
	lvl--;
	x= ( x-a[lvl] )%p[lvl]+p[lvl];
	solve(x,lvl);
}
int main(){
    for(int i=0;i<62;i++)
    	p[i]=(1ll<<i);           
	cin>>q;
	while(q--){
		ll type,x,k;
		cin>>type>>x;
		
		if(type==1){
			cin>>k;
			x=get(x);
			a[x]=(a[x]+k%p[x]+p[x]) % p[x];
		}
		
		if(type==2){
			cin>>k;
			x=get(x);
			for(int i=0;i+x<62;i++)
				a[i+x]=(a[i+x]+(1ll<<i)%p[i+x]*k%p[i+x]+p[i+x]) % p[i+x];
		}
		
		if(type==3){
			solve(x,get(x));
			cout<<endl;
		}
	
	}
}