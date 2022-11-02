#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file "a"

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n;
string S[200200];
char temp[22];
string cur;
set < ll > M;

ll gethash(string &s){
	ll hash = 0;
	for (int i=0;i<sz(s);i++)
		hash = hash*27 + (s[i] - 'a' + 1);
	return hash;
}

int main () {
	#ifdef LOCAL
	freopen(file".in", "r", stdin);
	freopen(file".out", "w", stdout);
	#endif

	scanf("%d\n", &n);
	for (int i=0;i<n;i++){
		gets(temp);
		int len = strlen(temp);
		cur = "";
		for (int j=0;j<len;j++)
			cur += temp[j];
		S[i] = cur;
	}

	for (int i=n-1;i>=0;i--){
		ll hash = gethash(S[i]);
		if (M.find(hash) != M.end()) continue;
		puts(S[i].c_str());
		M.insert(hash);
	}


	#ifdef LOCAL
	cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif

	return 0;
}