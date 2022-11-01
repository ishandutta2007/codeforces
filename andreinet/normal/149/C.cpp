#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 100005, Inf = 0x3f3f3f3f;

pair<int, int> A[Nmax];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int maxv = -Inf;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
        maxv = max(maxv, A[i].first);
    }
    sort(A + 1, A + N + 1);
    vector<int> ans1, ans2;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= N; ++i) {
        if (s1 < s2) {
            ans1.push_back(A[i].second);
            s1 += A[i].first;
        } else {
            ans2.push_back(A[i].second);
            s2 += A[i].first;
        }
    }
    cout << ans1.size() << '\n';
    for (int p: ans1) cout << p << ' ';
    cout << '\n' << ans2.size() << '\n';
    for (int p: ans2) cout << p << ' ';
    cout << endl;
}