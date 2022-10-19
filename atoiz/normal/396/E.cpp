#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

const int maxn = 1000007;

typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll A[maxn], k;
int prime[maxn], m;
vector<pll> periods[maxn], tmp;

void factorize(int x, vector<int> &vec)
{
	if (x < 2) return;
	int y;
    while (y = prime[x]) {
        vec.push_back(y); x /= y;
    }
    vec.push_back(x);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // prep
    for (int i = 2; i < maxn; ++i) if (!prime[i]) for (int j = i+i; j < maxn; j += i) prime[j] = i;

    // read
	cin >> m;
	for (int i = 0; i < m; ++i) {
        ll p, a; cin >> p >> a; periods[p].emplace_back(0, a);
	}
	cin >> k;

	int cnt = 0;
    for (int i = maxn - 1; i > 1; --i) if (!periods[i].empty()) {
        sort(periods[i].begin(), periods[i].end());
        tmp.clear();

        for (pll p1 : periods[i]) {
            if (tmp.empty() || tmp.back().se < p1.fi) tmp.push_back(p1);
            else tmp.back().se += p1.se - p1.fi;
        }

		vector<int> factors; factorize(i - 1, factors);
        for (pll p : tmp) {
            if (p.fi >= k) A[i] += p.se - p.fi;
            else {
                if (p.se > k) A[i] += p.se - k, p.se = k;
                for (int f : factors) periods[f].emplace_back(p.fi + 1, p.se + 1);
            }
        }

        if (A[i]) ++cnt;
    }

    cout << cnt << '\n';
    for (int i = 2; i < maxn; ++i) if (A[i]) cout << i << ' ' << A[i] << '\n';

    return 0;
}