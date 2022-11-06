#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T>
using heap = priority_queue<T, std::vector<T>, std::greater<T>>;

typedef long long lint;

static const int MX = int(1e7) + 31;
int dr[MX];
int nx[MX];
int pr[MX];
int pp[MX];

int a[1111111];
pair<int, int> b[1111111];
bool del[MX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i = 0; i < MX; i++) {
        pr[i] = i - 1;
        nx[i] = i + 1;
    }
    scid(n, m, k);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    sort(a, a + n);
    int d = -1;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (!del[x]) {
            d = x;
        }
        if (d == -1) {
            cout << -1;
            return 0;
        }
        
        dr[d]++;
        if (dr[d] == k) {
            del[d] = true;
            pr[nx[d]] = pr[d];
            if (pr[d] != -1) {
                nx[pr[d]] = nx[d];
            }
            d = pr[d];
        }
    }
    
    for (int i = 0; i < m; i++) {
        sci(b[i].first);
        b[i].second = i;
    }
    
    int ll = -1;
    for (int i = 0; i < MX; i++) {
        if (!del[i]) {
            ll = i;
        }
        pp[i] = ll;
    }
    
    sort(b, b + m);
    d = b[0].first;
    while (d >= 0 && del[d]) {
        d--;
    }
    
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        int x = pp[b[i].first];
        if (x != -1 && !del[x]) {
            d = x;
        }
        if (d == -1) {
            continue;
        }

        ans.push_back(b[i].second);
        dr[d]++;
        if (dr[d] == k) {
            del[d] = true;
            pr[nx[d]] = pr[d];
            if (pr[d] != -1) {
                nx[pr[d]] = nx[d];
            }
            d = pr[d];
        }
    }
    
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i + 1 << " ";
    }
    

    return 0;
}