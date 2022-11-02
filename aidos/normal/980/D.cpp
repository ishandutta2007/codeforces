#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
const int inf = (1ll << 30) - 1;
typedef long long ll;

using namespace std;
const long  double eps = 1e-15L;

int a[5050];
int cnt[5050];
int n;
int nxt[5050];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        nxt[i] = -1;
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 0) continue;
        for(int j = i + 1; j < n; j++){
            if(a[j] == 0) continue;
            ll x = a[i]*1ll*a[j];
            if(x < 0) continue;
            ll y = (ll)sqrt(x);
            if(y * y == x) nxt[j] = i;
        }
    }
    for(int i = 0; i < n; i++){
        int cur = 0;
        for(int j = i; j < n; j++){
            if(a[j] != 0 && nxt[j] < i) cur++;
            cnt[max(1, cur)]++;
        }
    }
    for(int i = 1; i <= n; i++) cout << cnt[i] << " ";
    return 0;
}