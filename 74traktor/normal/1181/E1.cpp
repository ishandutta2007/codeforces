#include <bits/stdc++.h>

using namespace std;

bool dfs(vector < vector < int > > Q){
    if ((int)Q.size() == 1) return true;
    vector < vector < int > > Q1;
    for (auto key : Q){
        Q1.push_back({key[0], 1, key[1], key[3], key[2]});
        Q1.push_back({key[2], 0, key[1], key[3], key[0]});
    }
    sort(Q1.begin(), Q1.end());
    int bal = 0;
    for (int i = 0; i < (int)Q1.size() - 1; ++i){
        auto key = Q1[i];
        if (key[1] == 1) bal++;
        else bal--;
        if (bal == 0){
            vector < vector < int > > to1, to2;
            for (int j = 0; j <= i; ++j){
                if (Q1[j][1] == 1) to1.push_back({Q1[j][0], Q1[j][2], Q1[j][4], Q1[j][3]});
            }
            for (int j = i + 1; j < (int)Q1.size(); ++j){
                if (Q1[j][1] == 1) to2.push_back({Q1[j][0], Q1[j][2], Q1[j][4], Q1[j][3]});
            }
            if (dfs(to1) && dfs(to2)) return true;
            cout << "NO" << '\n';
            exit(0);
        }
    }
    Q1 = {};
    for (auto key : Q){
        Q1.push_back({key[1], 1, key[0], key[2], key[3]});
        Q1.push_back({key[3], 0, key[0], key[2], key[3]});
    }
    sort(Q1.begin(), Q1.end());
    bal = 0;
    for (int i = 0; i < (int)Q1.size() - 1; ++i){
        if (Q1[i][1] == 1) bal++;
        else bal--;
        if (bal == 0){
            vector < vector < int > > to1, to2;
            for (int j = 0; j <= i; ++j){
                if (Q1[j][1] == 1) to1.push_back({Q1[j][2], Q1[j][0], Q1[j][3], Q1[j][4]});
            }
            for (int j = i + 1; j < (int)Q1.size(); ++j){
                if (Q1[j][1] == 1) to2.push_back({Q1[j][2], Q1[j][0], Q1[j][3], Q1[j][4]});
            }
            if (dfs(to1) && dfs(to2)) return true;
            cout << "NO" << '\n';
            exit(0);
        }
    }
    cout << "NO" << '\n';
    exit(0);
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x1, y1, x2, y2;
    cin >> n;
    vector < vector < int > > Q;
    for (int i = 1; i <= n; ++i){
        cin >> x1 >> y1 >> x2 >> y2;
        Q.push_back({x1, y1, x2, y2});
    }
    dfs(Q);
    cout << "YES" << '\n';
    return 0;
}