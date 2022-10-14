#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	string s;
	int mn[26], mx[26];
	fop (i,0,26) mn[i] = -1;
	cin >> n >> k >> s;
	fop (i,0,n) {
	    if (mn[s[i] - 'A'] == -1) mn[s[i] - 'A'] = i;
	    mx[s[i] - 'A'] = i;
	}
	set <int> now;
	bool is = true;
	fop (i,0,n) {
	    fop (j,0,26) {
	        if (mn[j] == i) now.insert(j);
	    }
	    if (now.size() > k) is = false;
	    fop (j,0,26) {
	        if (mx[j] == i) now.erase(j);
	    }
	}
	if (is) cout << "NO" << endl;
	else cout << "YES" << endl;
}