#include <bits/stdc++.h>

using namespace std;

int N, L, W;
int arr[400005];
map<int, int> mp;
int cnt[400005];
vector<int> ans[400005];
vector<bool> vis[400005];
vector<pair<int, int>> ord;

void dfs(int x, int y){
    if(vis[x][y]){
        return;
    }
    vis[x][y] = 1;
    ord.push_back({x, y});
    dfs((x+1)%L, (y+1)%W);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int tot = 0;
    for(auto p : mp){
        int q = p.second;
        q = min((int) (sqrt(N)), q);
        tot += q;
        cnt[q]++;
    }
    int sub = 0;
    int area = 1, len = 1;
    for(int n = (int) (sqrt(N)); n; n--){
        if(area < tot/n*n && tot/n >= n){
            area = tot/n*n;
            len = n;
        }
        sub += cnt[n];
        tot -= sub;
    }
    int wid = area/len;
    //cout << " " << len << " " << wid << endl;
    W = wid, L = len;
    for(int i = 0; i<len; i++){
        ans[i].resize(wid);
        vis[i].resize(wid);
    }
    for(int i = 0; i<len; i++){
        dfs(i, 0);
    }
    vector<pair<int, int>> v;
    for(auto p : mp){
        pair<int, int> q = {p.second, p.first};
        q.first = min(q.first, len);
        v.push_back(q);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    auto it = v.begin();
    for(auto p : ord){
        if(!it->first){
            it++;
        }
        //cout << " " << it->first << " " << p.first << " " << p.second << endl;
        ans[p.first][p.second] = it->second;
        it->first--;
    }
    cout << area << "\n" << len << " " << wid << "\n";
    for(int i = 0; i<len; i++){
        for(int j =0 ; j<wid; j++){
            assert(ans[i][j]);
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}