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
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i)
        cin >> a[i], a[i] = i-a[i];;
    vector<int> l(q);
    vector<vector<int>> r1(n+1);
    for(int i = 0; i < q; ++i){
        int y;
        cin >> l[i] >> y;
        l[i]++;
        r1[n-y].pb(i);
    }
    vector<int> b(n+1);
    vector<int> ans(q);
    int c;
    for(int i = 1; i <= n; i *= 2)
        c = i;
    int ans1 = 0;
    for(int r = 1; r <= n; ++r){
        int t = a[r];
        if(t >= 0){
            int pos = 0, cur = ans1;
            for(int j = c; j > 0; j /= 2)
                if(pos+j <= r && cur-b[pos+j] >= t)
                    pos += j, cur -= b[pos];
            ans1++;
            for(int i = pos+1; i <= n; i += (i&(-i)))
                b[i]++;
        }
        for(auto i: r1[r]){
            ans[i] = ans1;
            for(int j = l[i]; j > 0; j -= (j&(-j)))
                ans[i] -= b[j];
        }
    }
    for(int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
    return 0;
}