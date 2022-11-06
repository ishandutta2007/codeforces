#include <iostream>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); i++)
typedef vector<int> vi;

int main(){
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	vi r(n), m(n);
	rep(i,0,n) cin >> m[i];
	rep(i,0,n) cin >> r[i];
	int N = 720720;
	vector<bool> go(N);
	rep(i,0,n){
		for(int j = r[i]; j < N; j += m[i])
			go[j] = 1;
	}
	int ans = 0;
	rep(i,0,N) ans += go[i];
	cout << ans/double(N) << endl;
}