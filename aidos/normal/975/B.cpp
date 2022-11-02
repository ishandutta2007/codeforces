#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second

const int inf = (1ll << 30) - 1;
typedef long long ll;

using namespace std;

ll a[25];
ll b[25];
int main(){
    for(int i = 0; i < 14; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 0; i < 14; i++){
        if(a[i] == 0) continue;
        for(int j = 0; j < 14; j++){
            b[j] = a[j];
        }
        ll x = b[i];
        b[i] = 0;
        int j = (i + 1) % 14;
        while(j != 0 && x > 0){
            b[j]++;
            x--;
            j = (j + 1) % 14;
        }
        for(int k = 0; k < 14; k++) b[k] += x/14;
        x %= 14;

        while(x > 0){
            b[j]++;
            x--;
            j = (j + 1) % 14;
        }
        ll cur = 0;
        for(int k = 0; k < 14; k++) if(b[k] % 2 == 0) cur += b[k];
        ans = max(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}