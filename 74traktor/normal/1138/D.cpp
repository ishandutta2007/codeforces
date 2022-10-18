#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[2];
int b[2];

int h[500005];
int p[500005];
int mod;

void solve(){
    string s, s1;
    cin >> s >> s1;
    a[0] = 0, a[1] = 0, b[0] = 0, b[1] = 0;
    h[1] = s1[0] - '0' + 1;
    for (int i = 2; i <= (int)s1.size(); ++i) h[i] = (h[i - 1] + (s1[i - 1] - '0' + 1) * p[i - 1]) % mod;
    for (auto c : s){
        a[c - '0']++;
    }
    for (auto c : s1){
        b[c - '0']++;
    }
    string s2 = "";
    int ans = 0, k = 0, k1 = 0, max_len = 0;
    for (int i = (int)s1.size() - 1; i > 0; --i){
        bool f = false;
        /*for (int j = i; j < (int)s1.size(); ++j){
            if (s1[j] != s1[j - i]){
                f = true;
                break;
            }
        }*/
        int len = s1.size() - i;
        if (h[len] * p[i] % mod != (h[(int)s1.size()] - h[i] + mod) % mod) f = true;
        if (!f) max_len = (int)s1.size() - i;
    }
    //cout << max_len << end
    for (int i = 0; i < (int)s1.size() - max_len; ++i){
        if (s1[i] == '0') k++;
        else k1++;
    }
    for (int i = max_len; i < (int)s1.size(); ++i) s2 += s1[i];
    if (a[0] < b[0] || a[1] < b[1]){
        cout << s << '\n';
        exit(0);
    }
    //cout << max_len << endl;
    //cout << s2 << endl;
    //cout << k << " " << k1 << endl;
    //cout << a[0] << " " << b[0] << endl;
    a[0] -= b[0];
    a[1] -= b[1];
    //cout << a[0] << " " << a[1] << " " << k << " " << k1 << endl;
    cout << s1;
    while (a[0] >= k && a[1] >= k1){
        cout << s2;
        a[0] -= k;
        a[1] -= k1;
    }
    //cout << a[0] << " " << a[1] << endl;
    for (int i = 1; i <= a[0]; ++i) cout << "0";
    for (int i = 1; i <= a[1]; ++i) cout << "1";
    cout << '\n';
}
main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tests = 1;
    if (rand() % 2 == 0) mod = 1e9 + 9;
    else mod = 1e9 + 7;
    p[0] = 1;
    for (int i = 1; i <= 500001; ++i) p[i] = p[i - 1] * 29 % mod;
    while (tests--) solve();
    return 0;
}

/*
tractor74.ru
*/