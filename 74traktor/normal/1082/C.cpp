#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int x, y;
    cin >> n >> m;
    map < int, vector < int > > g;
    for (int i = 0; i < n; ++i){
        cin >> x >> y;
        if (g.find(x) == g.end()){
            vector < int > qwe;
            qwe.push_back(y);
            g[x] = qwe;
        }
        else
            g[x].push_back(y);
    }
    vector < int > prom;
    int gran = 0;
    map < int, vector < int > > G;
    set < int > spb;
    for (auto key : g){
        vector < int > ans;
        prom = key.second;
        sort(prom.begin(), prom.end());
        ans.push_back(prom[prom.size() - 1]);
        for (int i = prom.size() - 2; i >= 0; --i)
            ans.push_back(ans[prom.size() - i - 2] + prom[i]);
        G[key.first] = ans;
        gran = max(gran, (int)ans.size());
        spb.insert(key.first);
    }
    /*for (auto key : G){
        cout << key.first << endl;
        for (int i = 0; i < key.second.size(); ++i)
            cout << key.second[i] << ' ';
        cout << endl;
    }*/
    long long answ = 0;
    for (int i = 0; i <= gran; ++i){
        long long tec = 0;
        vector < int > ppt;
        for (auto key : spb){
            if (G[key].size() > i && G[key][i] >= 0)
            tec += G[key][i];
            if (G[key].size() <= i)
                ppt.push_back(key);
        }
        for (auto key : ppt)
            spb.erase(key);
        answ = max(answ, tec);
        //cout << i << " " << answ << endl;
    }
    cout << answ << endl;

    return 0;
}