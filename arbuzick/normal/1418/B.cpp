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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> l(n);
        for(int i = 0; i < n; ++i)
            cin >> l[i];
        vector<int> b;
        for(int i = 0; i < n; ++i)
            if(!l[i])
                b.pb(a[i]);
        sort(rall(b));
        int j = 0;
        for(int i = 0; i < n; ++i){
            if(l[i])
                cout << a[i] << ' ';
            else
                cout << b[j] << ' ', j++;
        }
        cout << '\n';
    }
    return 0;
}