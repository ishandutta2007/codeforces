#include <bits/stdc++.h>

using namespace std;

int imax;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        imax = 0;
        set < pair < int, int > > block;
        vector < int > ask1;
        vector < int > ask2;
        block.insert({1, n / 2});
        block.insert({n / 2 + 1, n});
        for (int j = 1; j <= n / 2; ++j){
            ask1.push_back(j);
        }
        for (int j = n / 2 + 1; j <= n; ++j) ask2.push_back(j);
        cout << ask1.size() << " " << ask2.size() << " ";
        for (auto key : ask1) cout << key << " ";
        for (auto key : ask2) cout << key << " ";
        cout << endl;
        cin >> x;
        imax = max(imax, x);
        while ((int)block.size() > 0){
            vector < pair < int, int > > add;
            ask1 = {};
            ask2 = {};
            for (auto key : block){
                if (key.first == key.second) continue;
                else{
                    int l = key.first, r = key.second, mid = (r + l) / 2;
                    for (int j = l; j <= mid; ++j) ask1.push_back(j);
                    for (int j = mid + 1; j <= r; ++j) ask2.push_back(j);
                    add.push_back({l, mid});
                    add.push_back({mid + 1, r});
                }
            }
            if ((int)ask1.size() == 0) break;
            cout << ask1.size() << " " << ask2.size() << " ";
            for (auto key : ask1) cout << key << " ";
            for (auto key : ask2) cout << key << " ";
            cout << endl;
            cin >> x;
            imax = max(imax, x);
            block = {};
            for (auto key : add){
                block.insert(key);
            }
        }
        cout << -1 << " " << imax << endl;
    }
    return 0;
}