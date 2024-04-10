#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, v;
        cin >> n >> v;
        v--;
        vector<int> d(n);
        for(int i = 0; i < n-1; ++i){
            int x, y;
            cin >> x >> y, x--, y--, d[x]++, d[y]++;
        }
        if(d[v] <= 1)
            cout << "Ayush\n";
        else if(n%2 == 1)
            cout << "Ashish\n";
        else
            cout << "Ayush\n";
    }
}