#include <bits/stdc++.h>

using namespace std;

int a[50], b[50];

long long ent(int r, int l){
    if (r == l)
        return 1;
    if (r == 1)
        return l;
    for (int i = 1; i <= l - r; i++)
        a[i] = 1;
    for (int i = l - r + 1; i <= l; i++)
        a[i] = i;
    for (int i = 1; i <= r; i++)
        b[i] = i;
    for (int i = 2; i <= r; i++){
        for (int j = 2; j <= l; j++){
            if (__gcd(b[i], a[j]) > 1){
                int x = __gcd(b[i], a[j]);
                b[i] /= x;
                a[j] /= x;
            }
        }
    }
    long long k = 1;
    for (int i = 1; i <= l; i++){
        k *= a[i];
    }
    return k;
}

int main() {
    long long ans = 0;
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 4; i < t; i++){
        if (i > n)
            break;
        if (t - i > m)
            continue;
        ans += ent(i, n) * ent(t - i, m);
    }
    cout << ans << endl;
}