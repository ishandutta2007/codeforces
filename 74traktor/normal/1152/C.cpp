#include <bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b){
    while (a > 0 && b > 0){
        int p = a % b;
        a = b;
        b = p;
    }
    return a + b;
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    int imin = a * b / gcd(a, b);
    int ans = 0;
    if (a == b){
        cout << 0 << '\n';
        return 0;
    }
    int t = abs(a - b);
    pair < int, int > answ = {imin, ans};
    for (int j = 1; j * j <= t; ++j){
        if (t % j == 0){
            int k = j * ((a + j - 1) / j) - a;
            answ = min(answ, {(a * b + k * (a + b) + k * k) / j, k});
            int jj = t / j;
            k = jj * ((a + jj - 1) / jj) - a;
            answ = min(answ, {(a * b + k * (a + b) + k * k) / jj, k});

        }
    }
    cout << answ.second << '\n';
    return 0;
}