# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# define ll long long
using namespace std;
int t;
ll n, m;
int main(){
    cin >> t;
    while (t--){
        cin >> n >> m;
        ll ans = (n - m) / (m + 1) * ((n - m) / (m + 1) + 1) / 2;
        ans = (m + 1) * ans + (n - m) % (m + 1) * ((n - m) / (m + 1) + 1);
        ans = n * (n + 1) / 2 - ans;
        cout << ans << endl;
    }
    return 0;
}