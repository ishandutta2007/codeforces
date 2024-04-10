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
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        int k = r%2+g%2+b%2+w%2;
        if(((r == 0 || g == 0 || b == 0) && k > 1) || k == 2)
            cout <<"No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}