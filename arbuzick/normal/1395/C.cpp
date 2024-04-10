#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
bool used[100][100];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    int ans = 0, c = 0;
    for(int k = 9; k >= 0; --k){
        bool f = 1;
        for(int i = 0; i < n; ++i){
            bool f1 = 0;
            for(int j = 0; j < m; ++j){
                //cout << (a[i]&b[j]&c) << ' ' << (a[i]&b[j]&(1 << k)) << '\n';
                if((a[i]&b[j]&c) == 0 && (a[i]&b[j]&(1 << k)) == 0)
                    f1 = 1;
            }
            //cout << '\n';
            f = f&f1;
        }
        //cout << '\n';
        if(f)
            c = c|(1 << k);
        else
            ans = ans|(1 << k);
    }
    cout << ans;
    return 0;
}