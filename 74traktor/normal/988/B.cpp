#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    multiset < pair < int, string > > g;
    for (int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        g.insert({(int)s.size(), s});
    }
    vector < pair < int, string > > a;
    for (auto key : g)
        a.push_back(key);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            bool f = false;
            for (int q = 0; q < a[i].first - a[j].first + 1; ++q){
                bool t = true;
                for (int z = 0; z < a[j].first; ++z){
                    if (a[j].second[z] != a[i].second[q + z])
                        t = false;
                }
                if (t) f = true;
            }
            if (!f){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (auto key : a) cout << key.second << endl;
    return 0;
}