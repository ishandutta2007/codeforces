#include <iostream>

using namespace std;

const int MAXN = 100007;
int N, A[MAXN], ans[MAXN];
bool on[MAXN];

int calc(int k)
{
    int squads = 0;
    for (int l = 1; l <= N; ++squads) {
        int diff = 0, r;
        for (r = l; r <= N; ++r) {
            if (!on[A[r]]) ++diff, on[A[r]] = 1;
            if (diff > k) break;
            // cout << k << ": " << l << ' ' << r << " - " << diff << endl;
        }
        for (int i = l; i <= r; ++i) on[A[i]] = 0;
        l = r;
    }
    return squads;
}

void answer(int l, int r)
{
    if (ans[l] == ans[r] || l + 1 >= r) {
        for (int i = l + 1; i < r; ++i) ans[i] = ans[l];
        return;
    }

    int m = (l + r) >> 1;
    ans[m] = calc(m);
    answer(l, m);
    answer(m, r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    ans[1] = calc(1), ans[N] = calc(N);
    answer(1, N);
    for (int i = 1; i <= N; ++i) cout << ans[i] << ' '; cout << endl;
}