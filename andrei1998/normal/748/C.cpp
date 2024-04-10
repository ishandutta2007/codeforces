#include <bits/stdc++.h>

using namespace std;

int cnt[256];

int main() {
    int N;
    string str;
    cin >> N >> str;
    int ans = 0;
    for (int i = 0; i < N; ) {
        memset(cnt, 0, sizeof cnt);
        int j = i - 1;
        while (j + 1 < str.size()) {
            ++cnt[str[++j]];
            if ((cnt['L'] && cnt['R']) || (cnt['U'] && cnt['D'])) {
                --cnt[str[j--]];
                break;
            }
        }
        ++ans;
        i = j + 1;
    }
    cout << ans << endl;
    return 0;
}