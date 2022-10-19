#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

#define M 500500

int n;
pair<int, int> p[M];
set<pair<int, int>> s;

void read() {
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        p[i] = make_pair(x, i);
        s.insert(make_pair(i, x));
    }

    sort(p, p + n);
}

void kill() {
    long long ans = 0;
    int sub = 0;
    for (int i = 0; i + 2 < n; ++i) {
        int x = p[i].first;
        int j = p[i].second;
        ans += 1ll * (n - i - 2) * (x - sub);
        sub = x;

        auto it = s.find(make_pair(j, x));
        auto last = --s.end();
        if (it != s.begin() && it != last) {
            auto l = it, r = it;
            --l;
            ++r;
            ans += (min(l -> second, r -> second) - sub);
        }
        
        s.erase(it);
    }
    cout << ans << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();


    return 0;
}