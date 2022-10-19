#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define int int64_t

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define SZ(x) (int)(x).size()

int a, b, c;

int sod(long long x)
{
	int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	vector<int> ans;
	FOR(s, 1, 82) {
        long long x = 1;
        for (int i = 0; i < a; ++i) x = x * s;
        x = x * b; x = x + c;
        if (sod(x) == s && 0 < x && x < int(1e9)) ans.push_back(x);
	}
	sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
}