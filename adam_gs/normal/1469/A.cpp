#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr(a, b) make_pair(a, b)
#define pb(a) push_back(a)
typedef long long ll;
const int LIM=1e5+7;
const ll MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string x;
		cin >> x;
		if(x.size()%2) {
			cout << "NO\n";
			continue;
		}
		int l=0, o=0, z=0;
		bool ans=true;
		for(auto i : x) {
			if(i==')') { ++z; --l; } else ++l;
			if(l<0) ans=false;
		}	
		l=0;
		for(int i=x.size()-1; i>=0; --i) {
			if(x[i]=='(') { ++o; --l; } else ++l;
			if(l<0) ans=false;
		}
		/*if(o>z) {
			l=0;
			for(auto i : x) {
				if(i=='(') ++l; else --l;
				l=max(l, 0);
			}
			if(l) ans=false;
		} else {
			l=0;
			for(int i=x.size()-1; i>=0; --i) {
				if(
			}
		}*/
		if(ans) cout << "YES"; else cout << "NO";
		cout << '\n';
	}
}