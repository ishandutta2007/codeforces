#include <bits/stdc++.h>

using namespace std;

#define int long long

double a[5001];
double pref[5001];


signed main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];
    double answ = 0.0;
    for (int i = k; i <= n; ++i){
        for (int j = 1; j <= n - i + 1; ++j){
            answ = max(answ, (double)(pref[j + i - 1] - pref[j - 1]) / (double)i);
        }
    }
    printf("%.12f", answ);
    return 0;
}