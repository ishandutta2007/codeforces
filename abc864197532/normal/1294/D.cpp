#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    int q, k, y, a, b;
    cin >> q >> k;
    set <pii> s1;
    int now[k];
    fop (i,0,k) {
        s1.insert({0,i});
        now[i] = 0;
    }
    while (q--) {
        cin >> y;
        y %= k;
        s1.erase({now[y], y});
        now[y]++;
        s1.insert({now[y], y});
        tie(a, b) = *s1.begin();
        cout << a * k + b << endl;
    }
}