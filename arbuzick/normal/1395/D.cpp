#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, d, m;
    cin >> n >> d >> m;
    vector<int> a, b;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if(x <= m)
            a.pb(x);
        else
            b.pb(x);
    }
    sort(all(a));
    sort(all(b));
    reverse(all(a));
    reverse(all(b));
    vector<int> pr_a(a.size()+1), pr_b(b.size()+1);
    for(int i = 0; i < a.size(); ++i)
        pr_a[i+1] = pr_a[i]+a[i];
    for(int i = 0; i < b.size(); ++i)
        pr_b[i+1] = pr_b[i]+b[i];
    int ans = 0;
    for(int i = 0; i < pr_a.size(); ++i){
        int k = (n-i-1)/(d+1)+1;
        ans = max(ans, pr_a[i]+pr_b[min(k*1ULL, 1ULL*b.size())]);
    }
    cout << ans;
    return 0;
}