#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set < int > a;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a.insert(x);
    }
    vector < int > b;
    for (int x = 1; x <= (int)3e9; x *= 2){
        b.push_back(x);
    }
    int max_dl = 1;
    vector < int > answer = {(*a.begin())};
    for (auto key : a){
        for (int i = 0; i < b.size(); ++i){
            vector < int > prom;
            prom.push_back(key);
            if (a.find(key - b[i]) != a.end())
                prom.push_back(key - b[i]);
            if (a.find(key + b[i]) != a.end())
                prom.push_back(key + b[i]);
            if (prom.size() > answer.size())
                answer = prom;
        }
    }
    cout << answer.size() << endl;
    for (auto key : answer) cout << key << " ";
    return 0;
}