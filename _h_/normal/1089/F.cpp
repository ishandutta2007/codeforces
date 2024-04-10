#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x,v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define rrep(i,a,b) for(int i = b; i --> a;)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	cin.exceptions(cin.failbit);

	ll n;
	cin >> n;
	for(ll p = 2; p*p < n; ++p){
		if(n % p == 0){
			ll q = n / p;
			if(__gcd(p,q) == 1){
				puts("YES");
				for(ll a = 1; a < p; ++a){
					if( (a * q + 1) % p == 0){
						ll b = q - (a * q + 1) / p;
						cout << 2 << endl;
						cout << a << ' ' << p << endl;	
						cout << b << ' ' << q << endl;	
						return 0;
					}
				}
			}
		}
	}
	puts("NO");
}