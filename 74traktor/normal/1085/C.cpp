#include <bits/stdc++.h>

using namespace std;

set < pair < int, int > > bfs(int x, int y, int x1, int y1, int x2, int y2){
    set < pair < int, int > > answ;
    if (x <= x1){
        for (int j = min(y, y1); j <= max(y, y1); ++j){
            answ.insert({x, j});
        }
        for (int i = x; i <= x1; ++i){
            answ.insert({i, y1});
        }
    }
    else{
        for (int j = min(y, y1); j <= max(y, y1); ++j){
            answ.insert({x1, j});
        }
        for (int i = x1; i <= x; ++i){
            answ.insert({i, y});
        }
    }
    int dist = 1e8;
    pair < int, int > T;
    for (auto key : answ){
        int h = key.first, t = key.second;
        if (abs(x2 - h) + abs(y2 - t) < dist){
            dist = abs(x2 - h) + abs(y2 - t);
            T = key;
        }
    }
    x = x2, y = y2;
    x1 = T.first, y1 = T.second;
    if (x <= x1){
        for (int j = min(y, y1); j <= max(y, y1); ++j){
            answ.insert({x, j});
        }
        for (int i = x; i <= x1; ++i){
            answ.insert({i, y1});
        }
    }
    else{
        for (int j = min(y, y1); j <= max(y, y1); ++j){
            answ.insert({x1, j});
        }
        for (int i = x1; i <= x; ++i){
            answ.insert({i, y});
        }
    }
    return answ;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    vector < set < pair < int, int > > > php;
    php.push_back(bfs(x, y, x1, y1, x2, y2));
    php.push_back(bfs(x, y, x2, y2, x1, y1));
    php.push_back(bfs(x1, y1, x2, y2, x, y));
    if (php[0].size() <= php[1].size() && php[0].size() <= php[2].size()){
        cout << php[0].size() << '\n';
        for (auto key : php[0]) cout << key.first << " " << key.second << '\n';
    }
    else if (php[1].size() <= php[0].size() && php[1].size() <= php[2].size()){
        cout << php[1].size() << '\n';
        for (auto key : php[1]) cout << key.first << " " << key.second << '\n';
    }
    else{
        cout << php[2].size() << '\n';
        for (auto key : php[2]) cout << key.first << " " << key.second << '\n';

    }
    return 0;
}