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
#define X first
#define Y second
#define MAXN 5000

bool vi[MAXN], color[MAXN], is = false;
vector <pii> nums[MAXN];
set <int> in_row;

void dfs(int n) {
    vi[n] = true;
    in_row.insert(n);
    for (pii i : nums[n]) {
        if (vi[i.X]) {
            if (in_row.count(i.X)) {
                color[i.Y] = true;
                is = true;
            }
        } else {
            dfs(i.X);
        }
    }
    in_row.erase(n);
}

int main () {
    int n, m, a, b;
    cin >> n >> m;
    fop (i,0,n) vi[i] = false;
    fop (i,0,m) color[i] = false;
    fop (i,0,m) {
        cin >> a >> b;
        nums[a-1].pb({b-1, i});
    }
    fop (i,0,n) {
        if (!vi[i]) dfs(i);
    }
    if (is) cout << 2 << endl;
    else cout << 1 << endl;
    fop (i,0,m) cout << int(color[i]) + 1 << " \n"[i == m - 1];
}