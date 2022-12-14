#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 500;
long long a[maxn], dp[maxn];

long long ent(long long l, long long r){
    return r * (r - 1) / 2;
}

int main() {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++){
        long long l = i;
        long long r = n;
        while (r - l > 1){
            if (a[(r + l) / 2] > a[i] + d)
                r = (r + l) / 2;
            else
                l = (r + l) / 2;
        }
        dp[i] = ent(2, l - i);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans += dp[i];
    }
    cout << ans << endl;
}