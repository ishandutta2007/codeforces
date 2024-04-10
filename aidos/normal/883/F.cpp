#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"

int n;
char c[1024];
string s, t;
set <string> w;

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", c);
		s = c;
		bool ok = 1;
		while(ok) {
			t = "";
			ok = 0;
			for (int i = 0; i < sz(s); ++i) {
				if (s[i] == 'u') {
					t += "oo";
					ok = 1;
					continue;
				}
				if (i + 1 < sz(s) && s[i] == 'k' && s[i + 1] == 'h') {
					t += 'h';
					ok = 1;
					++i;
					continue;
				}
				t += s[i];
			}
			s = t;
		}	
		w.insert(s);
	}

	printf("%d\n", sz(w));

	return 0;
}