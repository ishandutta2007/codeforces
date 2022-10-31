// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i =0;i<n;i++) cin >> a[i];
	if(n==1){
        cout<<"1 1\n"<<-a[0]<<'\n'<<"1 1\n0\n1 1\n0\n";
	}else{
        cout<<"1 "<<n<<'\n';
        for(ll i = 0;i<n;i++){
            cout<<(-a[i])*n<<' ';
        }
        cout<<"\n1 "<<n-1<<'\n';
        for(ll i=0;i<n-1;i++){
            cout<<a[i]*(n-1)<<' ';
        }
        cout<<"\n"<<n<<' '<<n<<'\n';
        cout<<a[n-1]*(n-1)<<'\n';
	}
}