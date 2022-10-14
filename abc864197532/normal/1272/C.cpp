#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
    int n,k;
    cin >> n >> k;
    string s;
    char c;
    cin >> s;
    set <char> cc;
    fop (i,0,k) {
        cin >> c;
        cc.insert(c);
    }
    lli sum = 0, kk = 0;
    fop (i,0,n) {
        kk++;
        if (!cc.count(s[i])) {
            kk = 0;
        }
        sum += kk;
    }
    cout << sum << endl;
}