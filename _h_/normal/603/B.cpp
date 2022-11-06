#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
typedef long long ll;
const ll md = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll p,k;
	cin >> p >> k;
	ll e;
	if(k == 0){
		e = p-1;
	} else {
		ll o = 0, x = 1;
		do {
			x = x*k%p;
			++o;
		} while(x != 1);
		e = (p-1)/o;
		if(k == 1) ++e;
	}
	ll ans = 1;
	while(e--) ans = ans * p % md;
	cout << ans << endl;
}