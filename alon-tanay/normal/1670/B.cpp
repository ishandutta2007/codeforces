#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<int,int>
#define pl pair<ll,ll>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<bool> special(26);
        string str;
        cin >> str;
        int k;
        cin >> k;
        for(int i = 0; i < k; i ++) {
            char c;
            cin >> c;
            special[c-'a'] = true;
        }
        int res = 0;
        int lst = 0;
        vector<int> dist;
        for(int i = 0; i < n; i ++) {
            if(special[str[i]-'a']) {
                dist.push_back(i-lst);
                lst = i;
            }
        }
        for(int i = dist.size() - 1; i >= 0; i --) {
            res = max(res,dist[i]);
        }
        cout << res << "\n";
    }
    return 0;
}