#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
int n;
vector<int> a;
int solve(int l, int r, int c){
    int m = 1000000000;
    for(int i = l; i < r; ++i)
        m = min(m, a[i]-c);
    int l1 = l, r1;
    int ans = m;
    for(int i = l; i < r; ++i){
        r1 = i;
        if(a[i]-c == m || i+1 == r){
            if(a[i]-c != m)
                r1 = r;
            if(r1 > l1)
                ans += solve(l1, r1, c+m);
            l1 = i+1;
        }
    }
    return min(r-l, ans);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cout << solve(0, n, 0);
    return 0;
}