#include <bits/stdc++.h>
using namespace std;

int c[100000];
vector<bool> w(100000, false);
long long p[100000];

int main()
{
    int n, k;
    cin >> n >> k;
    long long s = 0;
    for(int i = 0; i < n; i++)
        cin >> c[i], s += c[i];
    for(int i = 0, t; i < k; i++)
        cin >> t, w[t - 1] = true;
    for(int i = 0; i < n; i++) {
        p[i] = s - c[i];
        if(w[i])
            s -= c[i];
    }
    long long ans = 0;
    if(w[0] == false && w[n-1] == false)
        ans += 1ll * c[0] * c[n-1];
    for(int i = 0; i < n; i++) {
        if(i && w[i - 1] == false && w[i] == false)
            ans += c[i - 1] * 1ll * c[i];
        if(w[i] == true)
            ans += c[i] * p[i];
    }
    cout << ans;
    return 0;
}