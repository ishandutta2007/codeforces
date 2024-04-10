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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> a;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            a.insert(x);
        }
        if(a.size() == 1)
            cout << n << '\n';
        else
            cout << 1 << '\n';
    }
    return 0;
}