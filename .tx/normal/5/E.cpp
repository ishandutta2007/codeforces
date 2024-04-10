#include <bits/stdc++.h>

using namespace std;

template<typename T>
void sci(T &t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T &t, Ts &... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template<typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int a[2222222];
int b[2222222];
int d[2222222];
int w[2222222];


int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scid(n);
    int mx = 0;
    int cmx = 0;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        a[i + n] = a[i];
        if (a[i] > mx) {
            mx = a[i];
            cmx = 0;
        }
        if (a[i] == mx) {
            cmx++;
        }
    }

    memset(w, -1, sizeof(w));

    deque<pair<int, int> > q;
    for (int i = 0; i < 2 * n; i++) {
        if (!q.empty() && q.back().second == i - n + 1) {
            q.pop_back();
        }
//        cout << "before i: " << i << "\n";
//        for (auto &p : q) {
//            cout << "(" << p.first << ", " << p.second << ") ";
//        }
//        cout << "\n";
        if (a[i] != mx) {
            auto it = upper_bound(q.begin(), q.end(), make_pair(a[i], int(1e9)));
            int v = it - q.begin() + (it == q.end() ? 0 : 1);
            b[i] = v;
            if (it != q.end()) {
                w[i] = it->second;
            }
        }
//        cout << "add " << b[i] << "\n";
        while (!q.empty() && q.front().first < a[i]) {
            q.pop_front();
        }
        q.push_front({a[i], i});
    }

    lint ans = 0;
    for (int i = n; i < 2 * n; i++) {
        ans += b[i];
    }

//    reverse(a, a + 2 * n);
//    while (!q.empty()) {
//        q.pop();
//    }
//    for (int i = 0; i < 2 * n; i++) {
//        while (!q.empty() && a[i] >= q.top().first) {
//            q.pop();
//        }
//        if (q.empty()) {
//            b[i] = 0;
//        } else {
//            b[i] = i - q.top().second;
//            if (q.top().first == mx) {
//                b[i]--;
//            }
//        }
//        q.push({a[i], i});
//    }
//
//    for (int i = n; i < 2 * n; i++) {
//        ans += b[i];
//    }

//    for (int i = 0; i < n; i++) {
//        if (a[i] == mx) {
//            ans += i;
//        }
//    }

    for (int i = n; i < 2 * n; i++) {
        if (a[i] == mx) {
            int j = i - 1;
            int cmx = 0;
            while (a[j] != mx) {
                if (a[j] >= cmx && w[j] != i - n) {//
                    ans++;
                }
                cmx = max(cmx, a[j]);
                j--;
            }
        }
    }

    ans += 1LL * cmx * (cmx - 1) / 2;

    cout << ans;

    return 0;
}