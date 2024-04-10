#include <bits/stdc++.h>

using namespace std;

int freq[100005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        int val;
        cin >> val;
        ++ freq[val];
    }

    int ans = 1;
    for (int i = 2; i <= 100000; ++ i) {
        int cnt = 0;
        for (int j = i; j <= 100000; j += i)
            cnt += freq[j];
        ans = max(cnt, ans);
    }

    cout << ans << '\n';
    return 0;
}