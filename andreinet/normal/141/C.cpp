#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 3005;

pair<int, string> A[Nmax];
int H[Nmax];
string names[Nmax];

void noSol() {
    cout << "-1\n";
    exit(0);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i].second >> A[i].first;
    }

    sort(A + 1, A + N + 1);
    for (int i = 1; i <= N; ++i) {
        int pos = N - i + 1;
        if (A[i].first >= i) noSol();
        H[pos] = i - A[i].first;
        for (int j = pos + 1; j <= N; ++j)
            if (H[j] >= H[pos])
                ++H[j];
        names[pos] = A[i].second;
    }

    reverse(names + 1, names + N + 1);
    reverse(H + 1, H + N + 1);
    for (int i = 1; i <= N; ++i)
        cout << names[i] << ' ' << H[i] << '\n';
}