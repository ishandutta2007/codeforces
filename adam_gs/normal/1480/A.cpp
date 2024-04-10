#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string x;
		cin >> x;
		rep(i, x.size()) {
			if(i%2==0) {
				if(x[i]=='a') {
					cout << 'b';
				} else cout << 'a';
			} else {
				if(x[i]=='z') {
					cout << 'y';
				} else cout << 'z';
			}
		}
		cout << '\n';
	}
}