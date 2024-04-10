#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve_case(){
    int n; cin >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    sort(w.begin(), w.end());
    int ans = 0;
    for(int s = 0; s <= 2 * n; s++){
        multiset<int> we;
        for(int i = 0; i < n; i++) we.insert(w[i]);
        int cnt = 0;
        while(we.size()){
            int cur = *we.begin();
            we.erase(we.find(cur));
            if(we.count(s - cur)){
                we.erase(we.find(s - cur));
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve_case();
    return 0;
}