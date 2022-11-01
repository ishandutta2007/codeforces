#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int N = S.length();

    int pos = -1, rb = -1;
    for (int i = 0; i < N - 1; ++i) {
        if ((S[i] - '0') % 2 == 0) {
            if (pos == -1) {
                pos = i;
                if (S[pos] > S.back()) rb = 0;
                else rb = 1;
            } else if (S[i] < S.back() && rb == 0) {
                pos = i;
                rb = 1;
            } else if (S[i] > S.back() && rb == 0) {
                pos = i;
            }
        }
    }
    if (pos != -1) swap(S[pos], S.back());

    if (pos == -1) puts("-1");
    else cout << S << '\n';
}