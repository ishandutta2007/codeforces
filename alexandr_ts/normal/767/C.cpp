#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e14 + 10;
const ld EPS = 1e-10;

int p[N], c[N];
vector <int> g[N];
bool used[N];
int one[N], two[N];
int sum[N];
bool er = false;

void dfs(int v, int val, int root) {
    if (er) return;
    used[v] = true;
    sum[v] += c[v];
    fr(i, g[v].size()) {
        dfs(g[v][i], val, root);
        sum[v] += sum[g[v][i]];
        if (one[g[v][i]] != -1)
            one[v] = one[g[v][i]];
    }
    if (sum[v] == val)
        one[v] = v;
    if (sum[v] == 2 * val)
        two[v] = v;
    if (two[v] == v && v != root) {
        fr(i, g[v].size())
            if (one[g[v][i]] != -1 && !er) {
                cout << one[g[v][i]] + 1 << " " << v + 1 << endl;
                er = true;
                return;//exit(0);
            }
    }
    if (er)
        return;
    //vector <int> nums;
    int num1 = -1, num2 = -1;
    fr(i, g[v].size()) {
        if (one[g[v][i]] != -1)
            if (num1 == -1) num1 = one[g[v][i]];
            else num2 = one[g[v][i]];
        if (num2 != -1 && !er) {
            cout << num1 + 1 << " " << num2 + 1;
            er = true;
            return;
            //exit(0);
        }
    }
    return;
    //cout << v << " " << sum[v] << " " << one[v] << " " << two[v] << endl;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, root;
    cin >> n;
    fill(one, one + n, -1);
    fill(two, two + n, -1);
    fr(i, n) {
        scanf("%d %d", &p[i], &c[i]);
        if (p[i])
            g[p[i] - 1].pb(i);
        else
            root = i;
    }
    int s = accumulate(c, c + n, 0);
    if (s % 3) {
        cout << -1;
        return 0;
    }
    int val = s / 3;
    //cout << val << endl;
    dfs(root, val, root);
    if (!er)
        cout << -1;
}