#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
typedef pair<int, int> pii;
static vector<pii> pairs;
static vector<vector<int>> adj;
static int ans [MAX];
static int vis [MAX];
static vector<int> perm;
static void bfs(int x){
    vector<int> in;
    vector<int> nums;
    list<int> q;
    vis[x] = 1;
    q.push_back(x);
    while(!q.empty()){
        int s = q.front();
        in.emplace_back(s);
        nums.emplace_back(perm[s]);
        q.pop_front();
        for(int n:adj[s]){
            if(vis[n] == 0){
                vis[n] = 1;
                q.push_back(n);
            }
        }
    }
    sort(in.begin(), in.end());
    sort(nums.rbegin(), nums.rend());
    for(int i = 0; i<in.size(); i++){
        ans[in[i]] = nums[i];
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++){
        vector<int> temp;
        adj.emplace_back(temp);
        int d;
        scanf("%d", &d);
        perm.emplace_back(d-1);
    }
    for(int i = 0; i<m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x-1].emplace_back(y-1);
        adj[y-1].emplace_back(x-1);
    }
    for(int i = 0; i<n; i++){
        if(vis[i] == 0){
            bfs(i);
        }
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i] + 1 << " " ;
    }
    return 0;
}