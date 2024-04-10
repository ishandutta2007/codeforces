#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
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
    reverse(all(a));
    reverse(all(b));
    int m1 = a[0];
    for(int i = 0; i < n; ++i)
        m1 = min(m1, a[i]);
    if(m1 != b.back()){
        cout << 0;
        return 0;
    }
    int ans = 1;
    int mod = 998244353;
    int j1 = 0, j2 = 0;
    for(int i = 0; i+1 < m; ++i){
        int m2 = a[j1];
        while(j1 < n && a[j1] != b[i])
            m2 = min(m2, a[j1]), j1++;
        if(j1 == n || m2 < b[i]){
            cout << 0;
            return 0;
        }
        while(j2 < n && (j2 <= j1 || a[j2] != b[i+1]))
            m2 = min(m2, a[j2]), j2++;
        if(j2 == n || m2 < b[i+1]){
            cout << 0;
            return 0;
        }
        int mid = j1+1;
        while(a[mid] >= b[i])
            mid++;
        ans = ans*(mid-j1)%mod;
        j1 = j2;
    }
    cout << ans;
    return 0;
}