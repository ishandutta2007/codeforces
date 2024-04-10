#include<bits/stdc++.h>

using namespace std;

#define int long long
int ok[20005];

inline void get(int x) {
    for (int i = 10; i >= 0; --i) {
        if ((x&(1 << i)) > 0) cout << 1;
        else cout << 0;
    }
    cout << " ";
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*for (int i = 1; i <= 20; ++i) {
        int f = 1;
        for (int j = 1; j <= 10000 && f; ++j) {
            if (ok[j] == 0) {
                for (int z = j + 1; z <= 10000; ++z) {
                    if (ok[z] == 0 && ok[(j^z)] == 0) {
                        ok[z] = 1, ok[j] = 1, ok[(j^z)] = 1;
                        cout << j << " " << z << " " << (j^z) << endl;
                        /*cout << j << " ";
                        get(j);
                        get(z);
                        cout << endl;*/
                        /*f = 0;
                        break;
                    }
                }
            }
        }
    }*/
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int numb = (n + 2) / 3;
        vector < int > a;
        for (int j = 0; j <= 61; j += 2) {
            int cnt = (1ll << j);
            if (numb > cnt) numb -= cnt;
            else {
                a.push_back((1ll << j) + numb - 1);
                int x = (1ll << j) + numb - 1, y = (1ll << (j + 1));
                for (int b = 0; b < j; b += 2) {
                    int d = (1ll << (b + 1)), sz = (1ll << (b + 1));
                    //cout << numb << " " << d << " " << sz << endl;
                    if (numb > d && (numb - d - 1) / sz % 2 == 0) y += (1ll << b);
                    d /= 2;
                    if (numb > d && (numb - d - 1) / sz % 2 == 0) y += (1ll << (b + 1));
                }
                a.push_back((x^y));
                a.push_back(y);
                break;
            }
        }
        sort(a.begin(), a.end());
        if (n % 3 == 1) cout << a[0];
        else if (n % 3 == 2) cout << a[1];
        else cout << a[2];
        cout << '\n';
    }
    return 0;
}