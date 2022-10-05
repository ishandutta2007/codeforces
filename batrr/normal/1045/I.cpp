	//By Don4ick
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qwer1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

using namespace std;
const int N = 1e6 + 123;
int n, sz;
map < int, int > cnt;
ll ans;
char s[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int mask = 0;
		scanf("%s", s);
		sz = strlen(s);
		for(int j = 0; j < sz; j++)
			mask ^= (1<<(s[j] - 'a'));
		ans += cnt[mask];
		for(int j = 0; j < 26; j++)
			ans += cnt[mask ^ (1<<j)];
		cnt[mask]++;
	}
	printf("%lld", ans);
	return 0;
}