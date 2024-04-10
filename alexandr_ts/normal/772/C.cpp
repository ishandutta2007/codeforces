#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e15 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

const int N = 2e5 + 10;
const int M = 1e3 + 10;

int gcd[N];

vector <int> g[N];
vector <int> divs;
int pr[N];

int d[N], a[N];

ll fgcd (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = fgcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
	g = fgcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    set <int> bad;
    fr(i, n) {
        cin >> a[i];
        bad.insert(a[i]);
    }
    for (int i = 1; i * i <= m; i++)
        if (m % i == 0)
            divs.pb(i), divs.pb(m / i);
    sort(divs.begin(), divs.end());
    fr(i, m) {
        if (bad.count(i)) continue;
        gcd[i] = __gcd(i, m);
        g[gcd[i]].pb(i);
    }

    for (int i = m; i >= 1; i--) {
        d[i] = 0;
        pr[i] = i;
        for (auto j: divs)
            if (j % i == 0) {
                if (d[j] > d[i])
                    pr[i] = j;
                d[i] = max(d[i], d[j]);
            }
        d[i] += g[i].size();
    }

    vector <int> nums;
    vector <int> answer;
    int cur = 1;
    for (auto t: g[cur])
        nums.pb(t);
    while (pr[cur] != cur) {
        cur = pr[cur];
        for (auto t: g[cur])
            nums.pb(t);
    }

    //for (auto t: nums)
    //    cout << t << " ";cout << endl;
    answer.pb(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        ll x1 = 0, y1 = 0, trash = 0;
        find_any_solution(nums[i - 1], -m, nums[i], x1, y1, trash);
        answer.pb(((x1) % m + m) % m);
    }
    cout << d[1] << endl;
    for (auto t: answer)
        cout << t << " ";cout << endl;


}