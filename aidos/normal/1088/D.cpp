#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int a[maxn];
int n;
int cnt[22];
int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}
void solve() {
    int val =  ask(0, 0);
    int a = 0, b = 0;
    for(int bit = 29; bit >= 0; bit--) {
        int x = ask(a^(1<<bit), b);
        int y = ask(a, b^(1<<bit));
        if(x == y) {
            if(val == 1) {
                a ^= 1<<bit;
                val = x;
            } else {
                b ^= 1<<bit;
                val = y;
            }
        } else if(x == -1){
            a ^= 1<<bit;
            b ^= 1<<bit;
        }
    }
    cout << "! " << a << " "<< b << endl;
}


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}