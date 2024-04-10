#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 3005;
pair<pair<int, int>, int> p[MAXN];
char col[MAXN];
int x[MAXN], y[MAXN], id[MAXN], prv[MAXN], nxt[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r, c, n, k;
    cin >> r >> c >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].first.first--;
        p[i].first.second--;
    }
    sort(p, p + n);
    for(int i = 0; i < n; i++) {
        x[i] = p[i].first.first;
        y[i] = p[i].first.second;
        swap(p[i].first.first, p[i].first.second);
        p[i].second = i;
    }
    sort(p, p + n);
    for(int i = 0; i < n; i++) {
        swap(p[i].first.first, p[i].first.second);
        id[p[i].second] = i;
    }
    long long ans = 0;
    for(int i = 0; i < r; i++) {
        set<int> st;
        for(int j = 0; j < n; j++) {
            col[j] = false;
            prv[j] = -1;
            nxt[j] = n;
        }
        int pos = 0;
        while(pos < n && x[pos] < i)
            pos++;
        int cnt = c * (c + 1) / 2;
        for(int j = i; j < r; j++) {
            while(pos < n && x[pos] == j) {
                set<int>::iterator it = st.insert(id[pos]).first,
                    lit = it, rit = it;
                int ll = id[pos], rr = n;
                if(lit != st.begin()) {
                    lit--;
                    nxt[*lit] = id[pos];
                    prv[id[pos]] = *lit;
                }
                rit++;
                if(rit != st.end()) {
                    rr = *rit;
                    nxt[id[pos]] = rr;
                }
                prv[rr] = id[pos];
                int curk = 1;
                while(prv[ll] > -1 && curk < k) {
                    ll = prv[ll];
                    curk++;
                }
                while(rr < n && curk < k) {
                    rr = nxt[rr];
                    curk++;
                }
                if(curk == k) {
                    while(true) {
                        int cntl = (prv[ll] == -1? p[ll].first.second + 1 :
                                    p[ll].first.second - p[prv[ll]].first.second),
                            cntr = (rr == n? c - p[prv[rr]].first.second :
                                    p[rr].first.second - p[prv[rr]].first.second);
                        cnt -= cntl * cntr;
                        if(ll == id[pos] || rr == n)
                            break;
                        ll = nxt[ll];
                        rr = nxt[rr];
                    }
                }
                pos++;
            }
            ans += cnt;
        }
    }
    ans = (long long)(r * (r + 1) / 2) * (c * (c + 1) / 2) - ans;
    cout << ans << '\n';
    return 0;
}