#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

using li = long long;

using arr = array<pair<int, int>, 4>;
vector<int> a;

void push(arr& a, pair<int, int> p) {
    for (int i = 0; i < 4; i++)
        if (p.second > a[i].second) {
            for (int j = 4 - 1; j > i; j--)
                a[j] = a[j - 1];
            a[i] = p;
            return;
        }
}

vector<int> ans_candies;
int k_limit;

struct segtree {
    vector<arr> top_5;
    
    segtree(int n): top_5(n * 4, arr()) {
    }
    
    void build(int t, int l, int r, vector<pair<int, int>>& to) {
        if (l == r) {
            top_5[t][0] = make_pair(a[l], 1);
            to.emplace_back(a[l], 1);
            return;
        }
        
        vector<pair<int, int>> x, y;
        int m = (l + r) / 2;
        build(t * 2 + 1, l, m, x);
        build(t * 2 + 2, m + 1, r, y);
        to.reserve(x.size() + y.size());
        
        int xp = 0, yp = 0;
        
        while (xp < x.size() || yp < y.size()) {
            if (xp == x.size()) {
                to.push_back(y[yp++]);
            }
            else if (yp == y.size()) {
                to.push_back(x[xp++]);
            }
            else {
                if (x[xp].first == y[yp].first) {
                    to.push_back(make_pair(x[xp].first, x[xp].second + y[yp].second));
                    xp++;
                    yp++;
                }
                else if (x[xp].first < y[yp].first) {
                    to.push_back(x[xp]); xp++;
                }
                else {
                    to.push_back(y[yp]); yp++;
                }
            }
            
            push(top_5[t], to.back());
        }
        
        //printf("at %d..%d: ", l + 1, r + 1); for (auto it: to) printf("%d - %d times, ", it.first, it.second); printf("\n");
    }
    
    void query(int t, int l, int r, int x, int y) {
        if (x > r || y < l) return;
        
        if (l >= x && r <= y) {
            for (int i = 0; i < k_limit; i++)
                if (top_5[t][i].second > 0)
                    ans_candies.push_back(top_5[t][i].first);
            return;
        }
        
        int m = (l + r) / 2;
        query(t * 2 + 1, l, m, x, y);
        query(t * 2 + 2, m + 1, r, x, y);
    }
};

vector<vector<int>> positions;

void solve(bool read) {
    int n, q;
    if (read)
        cin >> n >> q;
    else {
        n = q = 3e5;
    }
    
    a.resize(n);
    positions.resize(n + 1);
    for (int i = 0; i < n; i++) {
        if (read)
            cin >> a[i];
        else {
            if (rand() % 5 == 0)
                a[i] = i + 1;
            else
                a[i] = rand() % 5 + 1;
        }
        positions[a[i]].push_back(i);
    }
    
    segtree s(n);
    vector<pair<int, int>> a_sorted;
    s.build(0, 0, n - 1, a_sorted);
    
    for (int i = 0; i < q; i++) {
        int l, r, k;
        if (read) {
            cin >> l >> r >> k;
            l--; r--;
        }
        else {
            l = rand() % 1000;
            r = n - 1 - rand() % 1000;
            k = 5;
        }
        
        ans_candies.clear();
        k_limit = k - 1;
        s.query(0, 0, n - 1, l, r);
        sort(all(ans_candies));
        ans_candies.erase(unique(all(ans_candies)), ans_candies.end());
        
        //printf("candidates: "); for (int x: ans_candies) printf("%d ", x); printf("\n");
        
        const int INF = 1e9;
        int answer = INF;
        
        int at_least = (r - l + 1) / k + 1;
        
        for (int x: ans_candies) {
            vector<int>& pos = positions[x];
            if (pos.size() < at_least) continue;
            
            int i1 = lower_bound(all(pos), r + 1) - pos.begin();
            if (i1 < at_least) continue;
            
            int i2 = lower_bound(all(pos), l) - pos.begin();
            
            int count = i1 - i2;
            //printf("%d count %d\n", x, count);
            if (count >= at_least)
                answer = min(answer, x);
        }
            
        if (answer == INF)
            cout << "-1\n";
        else
            cout << answer << "\n";
    }
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    solve(true);
    
    return 0;
}