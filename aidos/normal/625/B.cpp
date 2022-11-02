#include <bits/stdc++.h>

#define ft first
#define st second
#define mp make_pair
#define pb push_back
#define sc1(a) scanf("%d\n", &a)
#define sc2(a, b) scanf("%d %d\n", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d\n", &a, &b, &c)
#define pr(n) printf("%d", n)
#define scl(n) scanf("%I64d", &n)
#define prl(n) printf("%I64d", n)
#define sz(n) int(n.size())


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e5 + 123;
const int inf = 1e9+7;
const ll INF = 1e18 + 7;

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

set <pii> sc;
string s, t;
vector <int> v;
int ans, p[N];
bool u[N];


int main ()
{
	cin >> s >> t;

	v = z_function(t + "#" + s); 

	int n = sz(s);
	for (int i = sz(t) + 1; i <= n + sz(t); i ++)
	{
		if (v[i] == sz(t))
		{
			sc.insert(mp(i - sz(t) - 1, i - sz(t) - 1 + v[i]));
			for (int j = i - sz(t) - 1; j < i - sz(t) - 1 + v[i]; j ++)
			{
				p[j] ++;	
			}
		}	
	}

	int mx, q;
	for (auto it = sc.begin(); it != sc.end(); it ++)
	{
	 	pii cur = *it;
	 	mx = 0, q = - 1;
	 	bool ok = false;
	 	for (int i = cur.ft; i < cur.st; i ++)
	 	{
	 		if (u[i])
	 		{
	 			ok = true;
	 			break;
	 		}
	 		if (mx <= p[i])
	 		{
	 			mx = p[i];
	 			q = i;	
	 		}
	 		p[i] --;
	 	}
	 	if (!ok) ans ++;
	 	u[q] = true;
	}

	cout << ans;

}