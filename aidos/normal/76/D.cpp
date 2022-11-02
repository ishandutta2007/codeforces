#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353;
const int inf = (1<<30) - 1;

unsigned long long a, b;
void solve() {
    cin >> a >> b;
    unsigned long long c = 0, d = 0;

    if(a < b) {
        cout << -1 << "\n";
        return;
    }
    a -= b;
    d = b;
    for(int i = 63; i >= 0; i--) {
        unsigned long long cur = 1;
        cur <<= i;
        if(b&cur) {
            continue;
        }
        if(a >= cur) {
            a -= cur;
            if(a >= cur) {
                c += cur;
                d += cur;
                a -= cur;
            } else {
                a += cur;
            }
        }
    }
    if(a == 0) {
        cout << c << " "<< d << "\n";
    }else {
        cout << -1 << "\n";
    }
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}