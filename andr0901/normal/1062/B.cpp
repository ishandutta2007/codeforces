#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define ll long long

map <int, int> factorize(int n) {
    map <int, int> ans;
    for (int i = 2; i * i <= n; i++) {
        while (!(n % i)) {
            ans[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        ans[n]++;
    }
    return ans;
}

pii calcPow(int n) {
    if (n == 0)
        return {0, 0};
    int t = 1;
    int k = 0;
    while (t < n) {
        t *= 2;
        k++;
    }
    return {t, k};
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    map <int, int> deg = factorize(n);
    int f = 0;
    int ans = 0;
    int ANS = 1;
    int maxdeg = 0;
    for (pii i : deg) {
       /*cout << i.fs <<  " " << i.sc << "   " << calcPow(i.sc).fs << " " << calcPow(i.sc).sc << "\n";
        if (i.sc != calcPow(i.sc).fs || calcPow(i.sc).fs == 1)
            f = 1;*/
        ANS *= i.fs;
        ans = max(ans, calcPow(i.sc).sc);
        maxdeg = max(maxdeg, calcPow(i.sc).fs);
    }
    //cout << maxdeg;
    for (pii i : deg) {
        if (i.sc != maxdeg)
            f = 1;
    }
    if (ANS == n)
        cout << ANS << " " << 0;
    else
        cout << ANS << " " << ans + f;
    return 0;
}