#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
    int n,k,p;
    lli aa = 0, tmp;
    cin >> n >> p >> k;
    map <int,int> m1;
    fop (i,0,n) {
        cin >> tmp;
        long long ans = tmp;
        fop (j,0,3) {
            ans *= tmp;
            ans %= p;
        }
        ans -= ((1ll * k * tmp) % p);
        while (ans < 0) ans += p;
        if (m1.count(ans)) {
            aa += m1[ans];
            m1[ans]++;
        } else {
            m1[ans] = 1;
        }
    }
    cout << aa << endl;
}