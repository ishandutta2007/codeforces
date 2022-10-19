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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i].f, a[i].s = i+1;
        sort(all(a));
        if(a[0].f+a[1].f > a.back().f)
            cout << -1 << '\n';
        else
            cout << a[0].s << ' ' << a[1].s << ' ' << a.back().s << '\n';
    }
    return 0;
}