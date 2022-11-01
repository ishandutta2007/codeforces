#include <bits/stdc++.h>
 
using namespace std;

int n, k, a, b;
char c = 'G', d = 'B';
string s = "";

int main (int argc, char const *argv[]) {
    cin >> n >> k >> a >> b;
    if (min(a, b) == 0) {
        if (max(a, b) > k) puts("NO");
        else {
            for (int i = 0; i < n; ++i) {
                if (a == 0) cout << 'B';
                else cout << 'G';
            }
            cout << '\n';
        }
        return 0;
    }
    int l1 = (a + k - 1)/k, r1 = a;
    int l2 = (b + k - 1)/k, r2 = b;
    if (l1 > l2) {
        swap(l1, l2), swap(r1, r2);
        swap(a, b), swap(c, d);
    }
    // cout << l1 << " " << r1 << endl << l2 << " " << r2 << endl;
    if (r1 < l2 - 1) {
        puts("NO");
        return 0;
    }
    if (r1 == l2 - 1) {
        // z + 1 groups of d
        // z groups of c
        int l = 0, z = r1;
        string ss = "", tt = "";
        int szc = a/z, remc = a % z;
        for (int i = 0; i < szc; ++i) ss += c;
        int szd = b/(z + 1), remd = b % (z + 1);
        for (int i = 0; i < szd; ++i) tt += d;
        for (int i = 0, cc = z, dd = z + 1; i <= z + z; ++i) {
            if (i & 1) {
                s += ss;
                --cc;
                if (cc == remc) ss += c;
            } else {
                s += tt;
                --dd;
                if (dd == remd) tt += d;
            }
        }
        cout << s << '\n';
    } else {
        // z groups of c and d
        // cout << "yo\n";
        int l = 0, z = l2;
        string ss = "", tt = "";
        int szc = a/z, remc = a % z;
        for (int i = 0; i < szc; ++i) ss += c;
        int szd = b/z, remd = b % z;
        for (int i = 0; i < szd; ++i) tt += d;
        for (int i = 0, cc = z, dd = z; i < z + z; ++i) {
            if (i & 1) {
                s += ss;
                --cc;
                if (cc == remc) ss += c;
            } else {
                s += tt;
                --dd;
                if (dd == remd) tt += d;
            }
        }
        cout << s << '\n'; 
    }
    return 0;
}