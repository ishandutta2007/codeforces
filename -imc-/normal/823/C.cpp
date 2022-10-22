#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
    int x;
    cin >> x;
    return x;
}

const int N = 111111;
long long evev0[N], evev1[N];
vector<pair<long long, long long>> ev0, ev1;

void add(int pos, int x, int y) {
    if (pos < N) {
        evev0[pos] += x;
        evev1[pos] += y;
    } else {
        ev0.push_back({pos, x});
        ev1.push_back({pos, y});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n = nxt();
    long long k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }
    
    for (int x : a) {
        vector<int> xuis;
        for (int i = 1; (x + i - 1) >= i * i; ++i) {
            xuis.push_back((x + i - 1) / i);
        }
        for (int i = xuis.back() - 1; i >= 1; --i) {
            xuis.push_back(i);
        }
        reverse(all(xuis));
       
        for (int i = 0; i < (int)xuis.size(); ++i) {
            int k = xuis[i];
            int d = (x + k - 1) / k;
            add(d, 1ll * k * d - x, k);
            if (k > 1) {
                int nx = (x + xuis[i - 1] - 1) / xuis[i - 1];
                add(nx, -(1ll * k * nx - x), -k);
            }
//             ev0.emplace_back(d, 1ll * k * d - x);
//             if (k > 1) {
//                 int nx = (x + xuis[i - 1] - 1) / xuis[i - 1];
//                 ev0.emplace_back(nx, -(1ll * k * nx - x));
//             }
//             ev1.emplace_back(d, k);
//             if (k > 1) {
//                 ev1.emplace_back((x + xuis[i - 1] - 1) / xuis[i - 1], -k);
//             }
        }
    }
    
    sort(all(ev0));
    sort(all(ev1));
//     for (int i = 0; i < (int)ev0.size(); ++i) {
//         cerr << ev0[i].first << " " << ev0[i].second << " " << ev1[i].second << "\n";
//     }
    
    long long ans = 0;
    long long cur0 = 0, cur1 = 0, lst = 0;
    for (int i = 0; i < N; ++i) {
        long long d = i;
        cur0 += cur1 * (d - lst);
        lst = d;
        cur0 += evev0[i];
        cur1 += evev1[i];
        if (cur0 <= k) {
            ans = d;
        }
    }
    for (int i = 0; i < (int)ev0.size();) {
        long long d0 = 0, d1 = 0;
        int j = i;
        while (j < (int)ev0.size() && ev0[j].first == ev0[i].first) {
            d0 += ev0[j].second;
            d1 += ev1[j].second;
            ++j;
        }
        long long d = ev0[i].first;
        i = j;
        cur0 += cur1 * (d - lst);
        lst = d;
        cur0 += d0;
        cur1 += d1;
        
        if (cur0 <= k) {
            if (i < (int)ev0.size()) {
                ans = min(ev0[i].first - 1, d + (k - cur0) / cur1);
            } else {
                ans = d + (k - cur0) / cur1;
            }
        }
    }
    
    if (cur0 <= k) {
        ans = lst + (k - cur0) / cur1;
    }
    
    cout << ans << "\n";
    
    return 0;
}