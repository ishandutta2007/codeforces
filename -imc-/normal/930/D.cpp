#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

struct point {
    int x, y;
    
    point(int x = 0, int y = 0): x(x), y(y) {}
    
    bool operator<(const point& p) const {
        return make_pair(y, x) < make_pair(p.y, p.x);
    }
};

li subsolve(vector<point> pts, int oddity) {
    if (oddity == 1) {
        for (point& p: pts) {
            --p.x;
            --p.y;
        }
        oddity = 0;
    }
    
    const int MX = 2e5 + 100;
    vector<vector<point>> byX(2 * MX);
    for (point& p: pts) {
        p.x += MX;
        p.y += MX;
        byX[p.x].push_back(p);
    }
    
    set<point> left, right;
    
    for (point p: pts)
        right.insert(p);
    
    const int INF = 1e9;
    
    auto bounds = [&](set<point>& s) {
        if (s.empty()) return make_pair(INF, -INF);
        return make_pair(s.begin()->y, prev(s.end())->y);
    };
    
    li answer = 0;
    
    for (int x = 0; x < 2 * MX; ++x) {
        if (x % 2 == 0) {
            for (point p: byX[x]) {
                left.insert(p);
                right.erase(p);
            }
        }
        else {
            auto p1 = bounds(left), p2 = bounds(right);
            
            int l = max(p1.first, p2.first), r = min(p1.second, p2.second);
            if (l >= r) continue;
            
            answer += (r + 1) / 2 - l / 2;
        }
    }
    
    return answer;
}

void solve(bool __attribute__((unused)) read) {
    int n;
    cin >> n;
    
    vector<vector<point>> byOddity(2);
    
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        
        byOddity[((x + y) % 2 + 2) % 2].push_back(point(x - y, x + y));
    }
    
    const int INF = 1e9;
    
    li answer = 0;
    
    for (int t = 0; t < 2; ++t) {
        answer += subsolve(byOddity[t], t);
        
        /*
        int xMin = INF, xMax = -INF, yMin = INF, yMax = -INF;
        for (auto p: byOddity[t]) {
            xMin = min(xMin, p.x);
            xMax = max(xMax, p.x);
            yMin = min(yMin, p.y);
            yMax = max(yMax, p.y);
        }
        
        for (int x = -100; x <= 100; ++x)
            for (int y = -100; y <= 100; ++y)
                if ((x % 2 + 2) % 2 != t && (y % 2 + 2) % 2 != t && x >= xMin && x <= xMax && y >= yMin && y <= yMax) {
                    ++answer;
                }*/
    }
    
    cout << answer << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}