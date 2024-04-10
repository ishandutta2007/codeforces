#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pi pair<int,int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll sum = 0;
        unordered_map<ll,int> cnt;
        for(int i = 0 ;i < n; i ++) {
            ll x;
            cin >> x;
            cnt[x]++;
            sum += x;
        }
        stack<ll> st; st.push(sum);
        bool fail = false;
        while(st.size()) {
            ll cur = st.top();
            st.pop();
            if(cnt[cur]) {
                cnt[cur]--;
            } else {
                if(cur == 1) {
                    fail = true;
                    break;
                }
                st.push((cur+1)/2);
                st.push(cur/2);
            }
        }
        cout << ((fail ? "NO\n" : "YES\n"));
    }
    return 0;
}