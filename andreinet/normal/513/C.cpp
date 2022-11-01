#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 10;

pair<int, int> A[Nmax];
int Sz[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i].first >> A[i].second;
        Sz[i] = A[i].second - A[i].first + 1;
    }

    cout << setprecision(10) << fixed;

    double ans = 0;
    for (int sum = 1; sum <= 10000; ++sum) {
        double pt = 0, p = 1;
        for (int i = 1; i <= N; ++i) {
            p = 1;
            for (int j = 1; j <= N; ++j) {
                if (i == j) {
                    p *= (double) max(0, min(A[j].second - sum, Sz[j])) / Sz[j];
                } else {
                    p *= (double) max(0, min(sum - A[j].first + 1, Sz[j])) / Sz[j];
                }
            }
            pt += p;
        }
        for (int i = 1; i <= N; ++i) {
            p = 1;
            for (int j = 1; j <= N; ++j) {
                if (i == j) {
                    p *= (double) max(0, min(A[j].second - sum, Sz[j])) / Sz[j];
                } else {
                    p *= (double) max(0, min(sum - A[j].first, Sz[j])) / Sz[j];
                }
            }
            pt -= p;
        }
        p = 1;
        for (int i = 1; i <= N; ++i)
            p *= (double) max(0, min(sum - A[i].first + 1, Sz[i])) / Sz[i];
        pt += p;
        p = 1;
        for (int i = 1; i <= N; ++i)
            p *= (double) max(0, min(sum - A[i].first, Sz[i])) / Sz[i];
        pt -= p;
        for (int i = 1; i <= N; ++i) {
            p = 1;
            for (int j = 1; j <= N; ++j) {
                if (j == i) p *= (A[j].first <= sum && sum <= A[j].second ? (1.0D / Sz[j]): 0.0D);
                else p *= (double) max(0, min(sum - A[j].first, Sz[j])) / Sz[j];
            }
            pt -= p;
        }
        ans += pt * sum;
        //if (4 <= sum && sum <= 10) cout << pt << '\n';
    }
    cout << ans << '\n';
}