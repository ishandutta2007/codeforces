#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rll(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int x, k, y;
    cin >> x >> k >> y;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    vector<int> l, r;
    int l1 = 0;
    int j = 0;
    for(int i = 0; i < n; ++i){
        if(j < m && b[j] == a[i]){
            if(l1 != i)
                l.pb(l1), r.pb(i);
            l1 = i+1;
            j++;
        }
    }
    if(l1 != n)
        l.pb(l1), r.pb(n);
    if(j < m){
        cout << -1;
        return 0;
    }
    int ans = 0;
    for(int s = 0; s < l.size(); ++s){
        int m = 0, l2 = 0, r2 = 0;
        if(l[s] > 0)
            l2 = a[l[s]-1];
        if(r[s] < n)
            r2 = a[r[s]];
        for(int i = l[s]; i < r[s]; ++i)
            m = max(m, a[i]);
        int len = r[s]-l[s];
        if(len < k && m > l2 && m > r2){
            cout << -1;
            return 0;
        }
        if(x > y*k){
            if(l2 > m || r2 > m)
                ans += len*y;
            else
                ans += (len-k)*y+x;
        }else
            ans += len/k*x+len%k*y;
    }
    cout << ans;
    return 0;
}