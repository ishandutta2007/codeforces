#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 110;

vector<int> v[maxn];
int pr[maxn];

pii deepest(int u, int par = -1){
    pr[u] = par;
    pii ans = {0, u};
    for(int y : v[u]){
        if(y != par){
            pii p = deepest(y, u);
            p.first++;
            ans = max(ans, p);
        }
    }
    return ans;
}


vector<int> sees;

void go(int u, int &can_see, int par = -1){
    if(can_see == 0)
        return;
    sees.push_back(u);
    can_see--;
    for(int y : v[u]){
        if(y != par && can_see > 0){
            go(y, can_see, u);
            sees.push_back(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        for(int i = 2; i <= n; i++){
            int p;
            cin >> p;
            v[p].push_back(i);
            v[i].push_back(p);            
        }
        auto [bsth, u] = deepest(1);

        int tmp = u;
        while(tmp != 1){
            int dad =  pr[tmp];
            int id = -1;
            for(int i = 0; i < v[dad].size(); i++){
                if(v[dad][i] == tmp){
                    swap(v[dad][0], v[dad][i]);
                    break;
                }
            }
            tmp = dad;
        }

        sees.clear();
        int tmp_count = k;
        go(1, tmp_count);

        int down = min(bsth, k-1);

        vector<int> ans;
        for(int i = sees.size()-1; i >= down; i--){
            ans.push_back(sees[i]);
        }
        cout << ans.size()-1 << "\n";
        for(int x : ans){
            cout << x << " ";
        }
        cout << "\n";

        for(int i = 1; i <= n; i++){
            v[i].clear();
        }
    }
}