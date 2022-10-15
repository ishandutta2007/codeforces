/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

    ll n, m;
    cin >> n >> m;

    if(n == 1){
        cout << 1;
        return 0;
    }

    int ans[n];
    ms(ans);

    int l = 0, r = n - 1;
    ll h = pow(2, n - 2);
    for(int i = 1; i < n; i++){
        if(m <= h){
            ans[l++] = i;
        }else{
            ans[r--] = i;
            m -= h;
        }

        h /= 2;

    }

    ans[l] = n;

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";

}