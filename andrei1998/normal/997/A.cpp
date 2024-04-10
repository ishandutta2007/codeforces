#include <bits/stdc++.h>

using namespace std;

int N, X, Y;
string str;

int main() {
    cin >> N >> X >> Y;
    cin >> str;
    int cnt = 0;
    for (int i = 0, j; i < N; i = j + 1) {
        j = i;
        if (str[i] == '0') {
            ++ cnt;
            while (j + 1 < N && str[j + 1] == '0')
                ++ j;
        }
    }

    if (cnt == 0) {
        cout << "0\n";
        return 0;
    }

    long long int ans = Y;
    cnt --;
    ans += 1LL * min(X, Y) * cnt;
    cout << ans << endl;
    return 0;
}