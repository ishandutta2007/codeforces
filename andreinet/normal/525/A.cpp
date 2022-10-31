#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;

    int count[26] = {0}, ans = 0;
    for (int i = 0; i < int(S.length()); i += 2) {
        count[S[i] - 'a']++;
        int x = S[i + 1] - 'A';
        if (count[x] > 0) count[x]--;
        else ++ans;
    }

    cout << ans << '\n';
}