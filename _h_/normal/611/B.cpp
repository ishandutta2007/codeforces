#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef long long ll;

int main(){
	ll a,b;
	cin >> a >> b;
	int ans=0;
	rep(i,0,61)
		rep(j,0,i-1){
			ll n = (1LL<<i) - (1LL<<j) - 1;
			if(a<= n && n <= b)
				++ans;
		}
	cout << ans << endl;
}