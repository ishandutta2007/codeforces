#include <bits/stdc++.h>

using namespace std;

map < int, multiset < int > > G;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i){
        cin >> s;
        int bal = 0, min_bal = 0;
        for (auto c : s){
            if (c == '(') bal++;
            else bal--;
            min_bal = min(min_bal, bal);
        }
        if (bal >= 0 && min_bal < 0) continue;
        if (bal <= 0 && abs(min_bal) > -1 * bal) continue;
        G[bal].insert(min_bal);
    }
    int answ = 0;
    for (auto key : G){
        if (G.find(-1 * key.first) == G.end()) continue;
        vector < int > delete1;
        if (key.first == 0){
            while ((int)G[0].size() > 1){
                auto p = (*G[0].begin());
                G[0].erase(G[0].find(p));
                if (p < 0){
                    if ((*G[0].rbegin()) >= 0){
                        answ++;
                        G[0].erase(G[0].find((*G[0].rbegin())));
                    }
                }
                else{
                    answ++;
                    int R = (*G[0].begin());
                    G[0].erase(G[0].find(R));
                }
            }
            continue;
        }
        for (auto p : key.second){
            if ((int)G[-1 * key.first].size() == 0) break;
            if (p < 0){
                if ((*G[-1 * key.first].rbegin()) >= 0){
                    answ++;
                    int R = (*G[-1 * key.first].rbegin());
                    G[-1 * key.first].erase(G[-1 * key.first].find(R));
                }
                delete1.push_back(p);
            }
            else{
                answ++;
                int R = (*(G[-1 * key.first].begin()));
                G[-1 * key.first].erase(G[-1 * key.first].find(R));
                delete1.push_back(p);
            }
        }
        for (auto key1 : delete1) G[key.first].erase(G[key.first].find(key1));
    }
    cout << answ << endl;
}