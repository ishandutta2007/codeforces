#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int gcd(int a, int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    map <int, int> a;
    a[3] = 1;
a[7] = 1;
a[15] = 5;
a[31] = 1;
a[63] = 21;
a[127] = 1;
a[255] = 85;
a[511] = 73;
a[1023] = 341;
a[2047] = 89;
a[4095] = 1365;
a[8191] = 1;
a[16383] = 5461;
a[32767] = 4681;
a[65535] = 21845;
a[131070] = 1;
a[131071] = 1;
a[262143] = 87381;
a[524287] = 1;
a[1048575] = 349525;
a[2097151] = 299593;
a[4194303] = 1398101;
a[8388607] = 178481;
a[16777215] = 5592405;
a[33554431] = 1082401;
    set <int> s;
    int last = 2;
    forn (i, 1, 25) {
        last *= 2;
        s.insert(last - 1);
        /*int ans = 0;
        forn (j, 1, last - 1)
            ans = max(ans, gcd((last - 1) ^ j, (last - 1) & j));
        a[last - 1] = ans;*/
    }
    /*for (auto i : a)
        cout << "a[" << i.fs << "] = " << i.sc << ";\n";*/
    while (q --> 0) {
        int x;
        cin >> x;
        if (s.find(x) != s.end())
            cout << a[x];
        else
            cout << *s.upper_bound(x);
        cout << "\n";
    }
    return 0;
}