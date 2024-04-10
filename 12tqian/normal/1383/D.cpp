#include<bits/stdc++.h>
using namespace std;
const int MAX = 255;
int a[MAX][MAX];
int ans[MAX][MAX];
int n, m;
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
bool valid(int i, int j){
    if(i < 0 || i >= n) return false;
    if(j < 0 || j >= m) return false;
    return true;
}
int num_neighbors(int i, int j){
    int res = 0;
    for(int d = 0; d < 4; d++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if(valid(ni, nj) == false) continue;
        if(ans[ni][nj] != 0) res++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    set<int> rows;
    for(int i = 0; i < n; i++){
        int rowmax = 0;
        for(int j = 0; j < m; j++){
            rowmax = max(rowmax, a[i][j]);
        }
        rows.insert(rowmax);
    }
    set<int> cols;
    for(int j = 0; j < m; j++){
        int colmax = 0;
        for(int i = 0; i < n; i++){
            colmax = max(colmax, a[i][j]);
        }
        cols.insert(colmax);
    }
    int ci = -1; int cj = -1;
    vector<int> bad;
    for(int i = n * m; i >= 1; i--){
        if(rows.count(i) && cols.count(i)){
            ci++; cj++;
            ans[ci][cj] = i;
        }
        else if(rows.count(i)){
            ci++;
            ans[ci][cj] = i;
        }
        else if(cols.count(i)){
            cj++;
            ans[ci][cj] = i;
        }
        else{
            bad.emplace_back(i);
        }
    }
    set<pair<int, int>> available;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ans[i][j] != 0) continue;
            if(num_neighbors(i, j) != 2) continue;
            available.insert(make_pair(i, j));
        }
    }
    for(int i: bad){
        pair<int, int> pos = *available.begin();
        available.erase(pos);
        ans[pos.first][pos.second] = i;
        for(int d = 0; d < 4; d++){
            int ni = pos.first + di[d];
            int nj = pos.second + dj[d];
            if(valid(ni, nj) == false) continue;
            if(ans[ni][nj] != 0) continue;
            if(num_neighbors(ni, nj) != 2) continue;
            available.insert(make_pair(ni, nj));
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}