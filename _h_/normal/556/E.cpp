#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,a,b) for(ll (i)=(ll)(a); (i) < (ll)(b); ++(i))
#define mp make_pair
typedef long long ll;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,q;
	cin >> n >> q;
	map<ll,ll> ansh, ansv;
	ansh[n+1] = 0;ansv[n+1] = 0;
	ansh[0]   = 0;ansv[0]   = n+1;
	rep(i,0,q){
		ll x,y,svar;
		string a;
		cin >> x >> y >> a;
		if(a == "L"){
			auto p = ansh.lower_bound(y);
			auto z = ansv.upper_bound(x);
			--z;
			if(p->first == y){
				svar = 0;
			}
			else {if(z->first > n+1-p->first){
				svar = x-z->first;
			} else {
				svar = p->second + p->first-y;
			}
			if(svar != 0)
				ansh[y] = svar;}
		} else {
			auto p = ansh.upper_bound(y);
			auto z = ansv.lower_bound(x);
			--p;
			if(z->first == x){
				svar = 0;
			} else {if(p->first > n+1-z->first){
				svar = y-p->first;
			} else {
				svar = z->second + z->first-x;
			}
			if(svar != 0)
				ansv[x] = svar;}
		}
		cout << svar << endl;
	}
}