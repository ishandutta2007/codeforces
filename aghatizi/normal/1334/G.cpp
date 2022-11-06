#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

struct point {double x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, point b) {return (point) {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x}; }
point operator / (point a, double x) {return (point) {a.x / x, a.y / x}; }

const int maxb = 18;
const int N = (1 << maxb);
const int maxn = N + 20;
const double pi = acos(-1);
const double eps = 1e-3;

int r[maxn] , p[30];

bool ans[maxn];

point a[maxn];

void mul(point *a, int mode)
{
	for (int i = 0; i < N; i++)
		if (r[i] < i) swap(a[i], a[r[i]]);
	for (int len = 2; len <= N; len <<= 1) {
		point delta = (point) {cos(2 * pi / len * mode), sin(2 * pi / len * mode)};
		for (int i = 0; i < N; i += len) {
			point now = (point) {1, 0};
			for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
				point tmp = a[j];
				point tnp = a[k] * now;
				a[j] = tmp + tnp;
				a[k] = tmp - tnp;
				now = now * delta;
			}
		}
	}
	if (mode == -1) {
		for (int i = 0; i < N; i++)
			a[i] = a[i] / (4 * N);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 1; i < N; i++)
		r[i] = (r[i >> 1] >> 1) | ((i&1) << (maxb - 1));

	for(int i = 0; i < 26; i++)
		cin >> p[i] , p[i]--;

	string s , t;
	cin >> s >> t;
	reverse(s.begin() , s.end());

	int n = t.size() , m = s.size();

	memset(ans , 1 , sizeof ans);

	for(int ch = 0; ch < 26; ch++)
	{
		for(int i = 0; i < n; i++)
		{
			double x = t[i] - 'a' == ch || t[i] - 'a' == p[ch];
			double y = 0;
			if(i < m)
				y = s[i] - 'a' == ch;
			a[i] = (point) {x + y , x - y};
		}

		for(int i = n; i < N; i++)
			a[i] = (point) {0 , 0};

		int cnt = 0;
		for(int i = 0; i < m; i++)
			cnt += (s[i] - 'a' == ch);

		if(!cnt)
			continue;

		mul(a , 1);
		for(int i = 0; i < N; i++)
			a[i] = a[i] * a[i];
		mul(a , -1);

		for(int i = m - 1; i < n; i++)
			if(fabs(a[i].x - cnt) > eps)
				ans[i - m + 1] = 0;
	}

	for(int i = 0; i < n - m + 1; i++)
		cout << ans[i];
	cout << endl;
}