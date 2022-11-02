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

string s;
string a[1010];
char tmp[111];
int m;
int n;
int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif
	scanf("%d%s", &m, tmp);
	s = tmp;
	scanf("%d", &n);
	int mask = 0;
	int nmask = 0;
	for(int i = 0; i < m; i++){
		if(s[i] == '*') continue;
		int t = s[i] - 'a';
		mask |= (1<<t);
	}
	nmask = mask;
	for(int i = 0; i < 26;i++)
		mask ^= (1<<i);
   
	for(int i = 0; i < n; i++){
		scanf("%s", tmp);	
		a[i] = tmp;
		int good = 0;
		int ok = 1;
		for(int j = 0; j < m; j++){
			if(s[j] == '*') {
				int d = a[i][j] - 'a';
				if(nmask & (1<<d)) ok = 0;
				good |= (1<<d);
				continue;
			}
			if(s[j] != a[i][j]) {
				ok = 0;
				continue;
			}
		}
		if(ok) mask = (mask & good);
	}
	cout << __builtin_popcount(mask);

	return 0;
}