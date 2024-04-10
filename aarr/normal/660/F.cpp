#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200 * 1000 + 5;
const long long inf = 1e18 + N;

vector <pair <long long, pair <int, long long> > > vec;
int a[N];
long long ps1[N], ps2[N];

long long dcl(long long x, int y) {
    long long ans = x / y;
    if (x % y > 0) {
        ans++;
    }
    return ans;
}

long long inter(int h1, long long m1, int h2, long long m2) {
    return dcl(m2 - m1, h1 - h2);
}

void add(int h, long long m) {
    while (vec.size() && inter(h, m, vec.back().second.first, vec.back().second.second) <= vec.back().first) {
        vec.pop_back();
    }
    if (vec.size()) {
        vec.push_back({inter(h, m, vec.back().second.first, vec.back().second.second), {h, m}});
    }
    else {
    	vec.push_back({-inf, {h, m}});
	}
    
}

long long get(int k) {
	pair <long long, pair <int, long long> > p = {k, {-inf, -inf}};
	int x = upper_bound(vec.begin(), vec.end(), p) - vec.begin() - 1;
//	cout << "71 " << x << endl;
	return 1ll * vec[x].second.first * k + vec[x].second.second;
}

int32_t main() {
    int n;
    cin >> n;
    add(0, 0);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= -1;
        ps1[i] = ps1[i - 1] + a[i];
        ps2[i] = ps2[i - 1] + 1ll * i * a[i];
      //cout << "72 " << get(ps1[i]) << endl;
        ans = min(ans, ps2[i] - get(ps1[i]));
      //cout << "74 " << endl;
        add(i, -ps1[i - 1] * (i) + ps2[i - 1]);
    }
    cout << -ans;
    
}