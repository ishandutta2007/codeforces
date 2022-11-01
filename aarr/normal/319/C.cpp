#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;
const long long inf = 1e18 + N;

vector <pair <long long, pair <int, long long> > > vec;
int a[N], b[N];
long long dp[N];

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

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
       cin >> b[i]; 
    }
//    dp[1] = 0;
//	vec.push_back({-inf, {b[1], 0}});
    add(b[1], dp[1]);
    for (int i = 2; i <= n; i++) {
    	dp[i] = get(a[i]);
    	add(b[i], dp[i]);
    	//cout << "73 " << i << " " << dp[i] << " " << vec.size() << endl;
    //	for (int j = 0; j < vec.size(); j++) {
    //		cout << "72 " << vec[j].first << endl;
	//	}
	}
	cout << dp[n];
}