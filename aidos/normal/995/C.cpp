#include <bits/stdc++.h>
using namespace std;
#define pb push_back

pair<int, int> x[300100];
vector< pair<int, int> > g[300100];
int n, L;
int a[5];
int sz;
int ans[300300];
void dfs(int v, int cur){
    ans[v] = cur;
    for(auto u: g[v]){
        dfs(u.first, cur * u.second);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    L = 1500000;
    int R = 1000000;
    vector<int> pos;
    for(int i = 1; i <= n; i++){
        cin >> x[i].first >> x[i].second;
        pos.push_back(i);
    }
    sz = n + 1;
    while(pos.size() > 1){

        int len = min((int)pos.size(), 3);
        for(int i = 1; i <= len; i++){
            a[i] = pos.back();
            pos.pop_back();
        }
        int r = R;
        int fnd = false;
        if(len < 3) r = L;
        for(int i = 1; i <= len && fnd == false; i++){
            for(int j = i+1; j <= len && fnd == false; j++){
                for(int cur = 0; cur < 2 && fnd == false; cur++){
                    pair<int, int> y = x[a[j]];
                    if(cur){
                        y.first += x[a[i]].first;
                        y.second += x[a[i]].second;
                    }else{
                        y.first -= x[a[i]].first;
                        y.second -= x[a[i]].second;
                    }
                    if(y.first * 1ll * y.first + y.second * 1ll * y.second <= r * 1ll * r){
                        x[sz] = y;
                        g[sz].emplace_back(make_pair(a[j], 1));
                        g[sz].emplace_back(make_pair(a[i], 2*cur-1));
                        if(len == 3) pos.push_back(a[6-i-j]);
                        pos.push_back(sz);
                        sz++;
                        fnd = true;
                    }
                }
            }
        }
        //assert(fnd);
        //cout<<fnd << "\n";

    }
    dfs(sz-1, 1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";

	return 0;
}