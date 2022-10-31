#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> L(N);
    vector<int> R(N);
    vector<int> T(N);
    int res = 0;
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i] >> T[i];
    }
    vector<pair<int, int> > ll(N);
    vector<pair<int, int> > rr(N);
    for (int i = 0; i < N; i++) {
        ll[i].first = L[i];
        ll[i].second = i;
        rr[i].first = R[i] - T[i];
        rr[i].second = i;
    }
    sort(ll.begin(), ll.end());
    sort(rr.begin(), rr.end());
    set<pair<int, int> > ti;
    set<pair<int, int> > lti;
    for (int i = 0; i < N; i++) {
        lti.emplace(L[i] + T[i], i);
    }
    int INF = (int)1 << 62;
    int pos = -100;
    int curL = 0;
    int curR = 0;
    while (true) {
        int mn1 = ((ti.size() == 0) ? INF : (pos + (*ti.begin()).first));
        int mn2 = ((lti.size() == 0) ? INF : (*lti.begin()).first);
        res++;
        pos = min(mn1, mn2);

        while (curL < N && ll[curL].first <= pos) {
            int i = ll[curL].second;
            lti.erase(make_pair(L[i] + T[i], i));
            ti.emplace(T[i], i);
            curL++;
        }
        while (curR < N && rr[curR].first < pos) {
            int i = rr[curR].second;
            ti.erase(make_pair(T[i], i));
            curR++;
        }
        if (curR == N) break;
        if (ti.size() > 0) {
            int mnt = (*ti.begin()).first;
            int mn1 = ((curL < N) ? ll[curL].first : INF);
            int mn2 = R[(*ti.begin()).second];
            int step = (min(mn1, mn2) - pos) / mnt;
            pos += (step * mnt);
            res += step;
        }
        while (curL < N && ll[curL].first <= pos) {
            int i = ll[curL].second;
            lti.erase(make_pair(L[i] + T[i], i));
            ti.emplace(T[i], i);
            curL++;
        }
        while (curR < N && rr[curR].first < pos) {
            int i = rr[curR].second;
            ti.erase(make_pair(T[i], i));
            curR++;
        }
        if (curR == N) break;
    }
    cout << res << endl;
}