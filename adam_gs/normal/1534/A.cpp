#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int n, m;
char T[100][100], ans[100][100];
int odw[100][100];
void znajdz(int x, int y) {
        rep(i, n) rep(j, m) odw[i][j]=0;
        ans[x][y]=T[x][y];
        queue<pair<int,int>>q;
        q.push({x, y});
        odw[x][y]=1;
        while(!q.empty()) {
                int a=q.front().st, b=q.front().nd;
                q.pop();
                rep(i, 4) {
                        if(0<=a+dx[i] && a+dx[i]<n && 0<=b+dy[i] && b+dy[i]<m) {
                                if(!odw[a+dx[i]][b+dy[i]]) {
                                        q.push({a+dx[i], b+dy[i]});
                                        odw[a+dx[i]][b+dy[i]]=1;
                                        if(ans[a][b]=='W') {
                                                ans[a+dx[i]][b+dy[i]]='R';
                                        } else {
                                                ans[a+dx[i]][b+dy[i]]='W';
                                        }
                                }
                        }
                }
        }
        bool t=true;
        rep(i, n) rep(j, m) if(T[i][j]!='.' && ans[i][j]!=T[i][j]) t=false;
        if(t) {
                cout << "YES\n";
                rep(i, n) {
                        rep(j, m) cout << ans[i][j];
                        cout << '\n';
                }
        } else {
                cout << "NO\n";
        }
}
void solve() {
        cin >> n >> m;
        rep(i, n) rep(j, m) cin >> T[i][j];
        rep(i, n) rep(j, m) {
                if(T[i][j]!='.') {
                        znajdz(i, j);
                        return;
                }
        }
        cout << "YES\n";
        rep(i, n) {
                rep(j, m) {
                        cout << ((i+j)%2?'R':'W');
                }
                cout << '\n';
        }
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}