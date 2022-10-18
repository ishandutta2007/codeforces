/*
,  ?  ?
 Cadillac
 ,  
 , ,   (, few)
*/
#include<bits/stdc++.h>

using namespace std;

set < pair < int, int > > ans, used;
vector < pair < int, int > > go = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int i, int j) {
    used.insert({i, j});
    for (auto key : go) {
        i += key.first, j += key.second;
        if (ans.find({i, j}) != ans.end() && used.find({i, j}) == used.end()) dfs(i, j);
        i -= key.first, j -= key.second;
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = 1; i <= 2 * n + 1; ++i) ans.insert({i, 0});
        for (int i = 2; i <= 2 * n + 1; i += 2) ans.insert({i, -1}), ans.insert({i, 1});
        for (int i = 2; i <= 2 * n + 1; i += 4) {
            ans.insert({i, 2});
            ans.insert({i + 1, 2});
            ans.insert({i + 2, 2});
            ans.insert({i, -2});
            ans.insert({i + 1, -2});
            ans.insert({i + 2, -2});
        }
        ans.insert({0, 0});
        ans.insert({2 * n + 2, 0});
        for (int j = 0; j <= 10; ++j) {
            ans.insert({0, j});
            ans.insert({2 * n + 2, j});
        }
        for (int x = 0; x <= 2 * n + 2; ++x) ans.insert({x, 10});
    }
    else {
        for (int i = 1; i <= 2 * n + 1; ++i) ans.insert({i, 0});
        for (int i = 2; i <= 2 * n + 1; i += 2) ans.insert({i, -1}), ans.insert({i, 1});
        for (int i = 2; i <= 2 * n - 1; i += 4) {
            ans.insert({i, 2});
            ans.insert({i + 1, 2});
            ans.insert({i + 2, 2});
            ans.insert({i, -2});
            ans.insert({i + 1, -2});
            ans.insert({i + 2, -2});
        }
        ans.insert({2 * n + 2, 0});
        ans.insert({2 * n + 2, 1});
        ans.insert({2 * n + 2, 2});
        ans.insert({2 * n + 1, 2});
        ans.insert({2 * n, 2});
        for (int j = 0; j >= -10; --j) {
            ans.insert({0, j});
            ans.insert({2 * n, j});
        }
        for (int x = 0; x <= 2 * n; ++x) ans.insert({x, -10});
    }
    //dfs(1, 0);
    cout << ans.size() << '\n';
    for (auto key : ans) cout << key.first << " " << key.second << '\n';
    /*int answ = 0;
    for (auto key : ans) {
        int cnt = 0;
        for (auto elem : ans) {
            if (abs(key.first - elem.first) + abs(key.second - elem.second) == 1) cnt++;
        }
        if (cnt == 4) answ++;
        if (cnt % 2 == 1) cout << "RE" << endl;
    }
    cout << answ;
    if ((int)used.size() != (int)ans.size()) cout << "WA";*/
    return 0;
}