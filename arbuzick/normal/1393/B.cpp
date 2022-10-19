#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> used(100001, 0);
    int k2 = 0, k4 = 0;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        used[x]++;
        if(used[x]%2 == 0)
            k2++;
        if(used[x]%4 == 0)
            k4++;
    }
    int q;
    cin >> q;
    while(q--){
        char c;
        int x;
        cin >> c >> x;
        if(c == '-'){
            used[x]--;
            if(used[x]%2 == 1)
                k2--;
            if(used[x]%4 == 3)
                k4--;
        }else{
            used[x]++;
            if(used[x]%2 == 0)
                k2++;
            if(used[x]%4 == 0)
                k4++;
        }
        if(k4 == 0)
            cout << "NO\n";
        else if(k2 <= 3)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}