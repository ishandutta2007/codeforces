#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c, d;
    cin >> n >> c >> d;

    vector<pair<int, int>> A, B;
    for (int i = 0; i < n; ++i) {
        int beauty, price;
        cin >> beauty >> price;
        char type;
        cin >> type;
        (type == 'C' ? A: B).push_back(make_pair(price, beauty));
    }
    int ans = 0;
    sort(A.begin(), A.end());
    vector<int> maxBeautyA(SZ(A));
    for (int i = 0, beauty = 0; i < SZ(A); ++i) {
        beauty = max(beauty, A[i].second);
        maxBeautyA[i] = beauty;
    }
    for (int i = 1, j = SZ(A) - 1; i < SZ(A); ++i) {
        while (j >= 0 && A[i].first + A[j].first > c) {
            j--;
        }
        int x = min(j, i - 1);
        if (x != -1) {
            ans = max(ans, A[i].second + maxBeautyA[x]);
        }
    }
    sort(B.begin(), B.end());
    vector<int> maxBeautyB(SZ(B));
    for (int i = 0, beauty = 0; i < SZ(B); ++i) {
        beauty = max(beauty, B[i].second);
        maxBeautyB[i] = beauty;
    }
    for (int i = 1, j = SZ(B) - 1; i < SZ(B); ++i) {
        while (j >= 0 && B[i].first + B[j].first > d) {
            j--;
        }
        int x = min(j, i - 1);
        if (x != -1) {
            ans = max(ans, B[i].second + maxBeautyB[x]);
        }
    }
    int pos1 = -1, pos2 = -1;
    while (pos1 + 1 < SZ(A) && A[pos1 + 1].first <= c) {
        ++pos1;
    }
    while (pos2 + 1 < SZ(B) && B[pos2 + 1].first <= d) {
        ++pos2;
    }
    if (pos1 != -1 && pos2 != -1) {
        ans = max(ans, maxBeautyA[pos1] + maxBeautyB[pos2]);
    }
    cout << ans << '\n';


}