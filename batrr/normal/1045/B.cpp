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
const int N = 4e5 + 123;

int n, m;
ll a[N], b[N];
vector< ll > get(vector< ll > s, vector< ll > t){
	vector <ll> z(s.size() + t.size() + 1);
	vector <ll> q;
	for (auto i:s)
		q.pb(i);
	q.pb(-1);
	for (auto i:t)
		q.pb(i);
	for (int i=1, l=0, r=0; i< z.size(); ++i) {
		if (i <= r)
			z[i] = min (r-i+1ll, z[i-l]);
		while (i+z[i] < z.size() && q[z[i]] == q[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
				
	vector <ll> res;
	for (int id = s.size(); id < z.size(); ++id)
		if (z[id] == s.size())	
			res.pb(id - s.size() - 1);
	/*
	for(auto it : s)
		cerr << it << " "; cerr << endl;
	for(auto it : t)
		cerr << it << " "; cerr << endl;
	for(auto it : res)
		cerr << it << " "; cerr << endl;
	*/
	return res;				
} 
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		b[i] = (m - a[i]) % m;
		a[i + n] = a[i] + m;
	}	
	if(n == 1)
		cout << 1 << endl << a[0] * 2 % m, exit(0);
	sort(b, b + n);
	vector< ll > s, t, ans, res;
	for(int i = 1; i < n; i++)
		s.pb(b[i] - b[i - 1]);
	for(int i = 1; i < n + n; i++)
		t.pb(a[i] - a[i - 1]);
	res = get(s, t);
	for(auto it : res)
		ans.pb((a[it] - b[0] + m) % m);
	sort(all(ans));
	ans.resize(unique(all(ans)) - ans.begin());		
	printf("%d\n", (int)ans.size());
	for(auto it : ans)
		printf("%lld ",it);
	return 0;
}