#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll Main(){
   ll b,g,n;
	cin>>b>>g>>n;
	if(min(b,g)>=n)cout<<n+1;
	else if(min(b,g)<n&&max(b,g)>=n)cout<<min(b,g)+1;
	else{
		cout<<g+b-n+1;
	}
}
int32_t main(){
    ll t;
  //  cin >> t;
  t=1;
    while(t--) Main();
}