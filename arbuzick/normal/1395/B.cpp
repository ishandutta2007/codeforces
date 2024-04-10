#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
bool used[100][100];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<pair<int, int>> ans;
    ans.pb({x, y});
    used[x-1][y-1] = 1;
    ans.pb({1, y});
    used[0][y-1] = 1;
    for(int i = 0; i < n; ++i){
        int f = 0, add = 1;
        if(i%2 == 1)
            f = m-1, add = -1;
        for(int j = f; j < m && j >= 0; j += add)
            if(!used[i][j])
                ans.pb({i+1, j+1});
    }
    for(auto [i, j]: ans)
        cout << i << ' ' << j << '\n';
    return 0;
}