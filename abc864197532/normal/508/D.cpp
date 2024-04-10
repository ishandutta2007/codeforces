#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
const int N = 4000;
vector <int> adj[N];
vector <string> order;
map <string, int> m1;
vector <bool> vis;
int t = 0, n;
string ans = "";
int Count[N];

void dfs(int v) {
    while (adj[v].size()) {
        int u = adj[v].back(); adj[v].pop_back();
        dfs(u);
    }
    ans += order[v][1];
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,0,N) Count[i] = 0;
    cin >> n;
    string s;
    fop (i,0,n) {
        cin >> s;
        int a, b;
        string s1 = s.substr(0, 2), s2 = s.substr(1);
        if (m1.count(s1)) a = m1[s1];
        else a = t++, m1[s1] = a, order.pb(s1);
        if (m1.count(s2)) b = m1[s2];
        else b = t++, m1[s2] = b, order.pb(s2);
        adj[a].pb(b);
        Count[a]++;
        Count[b]--;
    }
    int k = 0, c = 0;
    bool is = true;
    fop (i,0,t) {
        if (Count[i] >= 2 or Count[i] < -2) {
            is = false;
        } else if (Count[i] == 1) {
            k = i;
            c++;
        } else if (Count[i] == -1) {
            c++;
        }
    }
    if (!is or c > 2) {
        cout << "NO" << endl;
        exit(0);
    }
    dfs(k);
    ans += order[k][0];
    reverse(ans.begin(), ans.end());
    if (ans.length() == n + 2) {
        cout << "YES" << endl << ans << endl;
    } else {
        cout << "NO" << endl;
    }
}