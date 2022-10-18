#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    multiset < int > use;
    for (int i = 0; i < n; ++i) use.insert(a[i]);
    for (int i = 0; i < n; ++i){
        multiset < int > prom = use;
        vector < int > ans;
        ans.push_back(a[i]);
        prom.erase(prom.find(a[i]));
        bool f = true;
        int pocl = a[i];
        while (prom.size() > 0 && f){

            if (prom.find(pocl / 3) != prom.end() && pocl % 3 == 0){
                ans.push_back(pocl / 3);
                prom.erase(prom.find(pocl / 3));
                pocl = pocl / 3;
                continue;
            }
            if (prom.find(2 * pocl) != prom.end()){
                ans.push_back(2 * pocl);
                prom.erase(prom.find(2 * pocl));
                 pocl = 2 * pocl;
                continue;
            }
            f = false;
        }
        if (f){
            for (auto key : ans)
                cout << key << " ";
            return 0;
        }
    }
    return 0;
}