#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a, b;
	cin >> a >> b;
	int ile=0;
	string ans="";
	rep(i, a.size()) {
		if(a[i]==b[i]) ans+=a[i];
		else {
			if(ile) ans+=a[i];
			else ans+=b[i];
			ile^=1;
		}
	}
	cout << (ile?"impossible":ans) << '\n';
}