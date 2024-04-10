#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve_case(){
    int n; cin >> n;
    string s; cin >> s;
    int zero = 0;
    int one = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') zero++;
        else one++;
    }
    if(one == n || one == 0){
        cout << n << '\n';
        for(int i = 0; i < n; i++) cout << i + 1 << " ";
        cout << '\n';
        return;
    }
    vector<int> id[2];
    vector<int> ans;
    int nxt = 1;
    for(int i = 0; i < n; i++){
        int t = s[i] - '0';
        int o = t ^ 1;
        if(id[o].size() == 0){
            id[t].push_back(nxt);
            ans.push_back(nxt);
            nxt++;
        }
        else{
            int val = id[o].back();
            id[o].pop_back();
            ans.push_back(val);
            id[t].push_back(val);
        }
    }
    cout << nxt - 1 << '\n';
    for(int x: ans) cout << x << " ";
    cout << '\n';
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve_case();
    return 0;
}