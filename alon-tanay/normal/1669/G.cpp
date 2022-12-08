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
        int n, m;
        cin >> n >> m;
        
        vector<vector<char>> mp(n+1,vector<char>(m));
        for(int ri = 0; ri < n; ri ++) {
            for(int ci = 0; ci < m; ci ++) {
                cin >> mp[ri][ci];
            }
        }
        vector<vector<char>> res(n+1,vector<char>(m,'.'));
        for(int ci = 0; ci < m; ci ++) {
            // cout << ci << "!" << endl;
            mp[n][ci] = 'o';
            int cnt = 0;
            for(int ri = 0; ri <= n; ri ++) {
                // cout << "  " << ri << ": ";
                if(mp[ri][ci] == '*') {
                    cnt ++;
                    // cout << "O -> " << cnt << endl;
                } else if(mp[ri][ci] == 'o') {
                    res[ri][ci] = 'o';
                    // cout << "  *: " << cnt << "(" << ri << " " << ci << endl;
                    while(cnt) {
                        // cout << ri - cnt << "?-------" << endl;
                        res[ri-cnt][ci] = '*';
                        cnt --;
                    }
                }
            }
        }
        for(int ri = 0; ri < n; ri ++) {
            for(int ci = 0; ci < m; ci ++) {
                cout << res[ri][ci];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}