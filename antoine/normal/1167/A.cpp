#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool f() {
	int n;
	string s;
	cin >>n >>s;
	const int i = s.find('8');
	if(i==-1)
		return false;
	return n-i>=11;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) cout << (f()?"YES":"NO") << endl;
	return 0;
}