#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
int lp[maxm];
int d1[maxn];
int d2[maxn];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    for(int i = 2; i < maxm; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            for (long long j = i * 1ll * i; j < maxm; j += i) {
                lp[j] = i;
            }
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int pr = lp[x];
        while(x % pr == 0) x /= pr;
        if(x == 1) {
            d1[i] = d2[i] = -1;
        } else {
            d1[i] = pr;
            d2[i] = x;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << d1[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++) {
        cout << d2[i] << " ";
    }
    cout << "\n";
    return 0;
}