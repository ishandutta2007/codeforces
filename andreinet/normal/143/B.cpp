#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int N = S.length();

    int pos = N;
    for (int i = 0; i < N; ++i)
        if (S[i] == '.')
            pos = i;

    if (pos == N) S.push_back('.');
    while (int(S.length()) < pos + 3)
        S.push_back('0');
    while (int(S.length()) > pos + 3)
        S.pop_back();

    for (int i = pos - 3; i >= 0 && '0' <= S[i] && S[i] <= '9'; i -= 3)
        if (i > 0 && '0' <= S[i - 1] && S[i - 1] <= '9')
            S.insert(S.begin() + i, ',');

    if (S.front() == '-') {
        S.erase(S.begin());
        S.insert(S.begin(), '$');
        S.insert(S.begin(), '(');
        S.push_back(')');
    } else {
        S.insert(S.begin(), '$');
    }

    cout << S << '\n';
}