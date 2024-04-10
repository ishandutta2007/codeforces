#include <bits/stdc++.h>

using namespace std;

#define long long long

const int M = 100100;

long w[M];
int n, m, l[M], r[M];
int pref[M], suff[M], d[M];
string s;

void read() {
    cin >> n >> m;
    cin >> s;
    s = "#" + s + "#";
}

void kill() {
    pref[0] = 0;
    suff[n + 1] = 0;

    l[1] = 0;
    r[n + 1] = n + 1;

    for (int i = 1; i <= n; ++i)
        if (s[i] == s[i - 1]) {
            pref[i] = pref[i - 1];
            l[i] = l[i - 1];
        }
        else {
            pref[i] = pref[i - 1] + 1;
            l[i] = i;
        }

    for (int i = n; i >= 1; --i)
        if (s[i] == s[i + 1]) {
            suff[i] = suff[i + 1];
            r[i] = r[i + 1];
        }
        else {
            suff[i] = 1 + suff[i + 1];
            r[i] = i;
        }

    d[1] = 1;
    for (int i = 2; i <= n; ++i) 
        if (s[i] == s[i - 1]) {
            d[i] = 1;
        } else {
            d[i] = 2;
            if (s[i] == s[i - 2])
                d[i] = 1 + d[i - 1];
        }

    //for (int i = 1; i <= n; ++i)
    //  cerr << s[i] << " " << d[i] << endl;


    long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += pref[i] - 1 + 1 + suff[i] - 1;
    ans *= m - 1;

    for (int i = 1; i <= n; ++i)
        ans -= d[i] - 1;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    kill();
    return 0;
}