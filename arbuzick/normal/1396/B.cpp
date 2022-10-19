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
        sort(all(a));
        int s = 0;
        for(int i = 0; i < n-1; ++i)
            s += a[i];
        if(a.back() > s){
            cout << "T\n";
        }else{
            s += a.back();
            if(s%2 == 0)
                cout << "HL\n";
            else
                cout << "T\n";
        }
    }
    return 0;
}