#include <bits/stdc++.h>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	n++;
	string s;
	cin >> s;
	s += '_';
	string w;
	bool in = false;
	int c1 = 0, c2 = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
			w += s[i];
			continue;
		}
		if(sz(w) > 0) {
			if(in)
				c2++;
			else
				c1 = max(c1, sz(w));
			w.clear();
		}
		if(s[i] == '(')
			in = true;
		if(s[i] == ')')
			in = false;
	}
	cout << c1 << ' ' << c2;
}