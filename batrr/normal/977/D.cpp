// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
ll n,g,a[maxn];
vector< pair< pair< ll,ll> , ll > > v;
int main(){
	IOS
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll x=a[i],p2=0,p3=0;
		while(x%2==0)
			x/=2,p2++;
		while(x%3==0)
			x/=3,p3++;
		v.pb(mp(mp(p2,p3),a[i]));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		int j=i;
		while(j<n && v[i].f.f==v[j].f.f)
			j++;
		for(int q=j-1;q>=i;q--)
			cout<<v[q].s<<" ";
		i=j-1;
	}	

}