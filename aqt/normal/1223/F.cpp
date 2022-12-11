#include <bits/stdc++.h>

using namespace std;

int T, N;
map<pair<long long, long long>, int> mp;
long long hsh[2] = {1145567221, 1092941341};
long long sd[2] = {350377, 363269};
stack<pair<long long, long long>> stk;
stack<int> tp;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        stk.push({0LL, 0LL});
        tp.push(0);
        mp[{0LL, 0LL}]++;
        long long ans = 0;
        for(int i = 1; i<=N; i++){
            int n;
            cin >> n;
            if(tp.top() == n){
                stk.pop();
                tp.pop();
                ans += mp[stk.top()];
                mp[stk.top()]++;
            }
            else{
                auto p = stk.top();
                p.first *= sd[0];
                p.first += n;
                p.first %= hsh[0];
                p.second *= sd[1];
                p.second += n;
                p.second %= hsh[1];
                ans += mp[p];
                mp[p]++;
                tp.push(n);
                stk.push(p);
            }
        }
        while(stk.size()){
            stk.pop();
            tp.pop();
        }
        mp.clear();
        cout << ans << "\n";
    }
}