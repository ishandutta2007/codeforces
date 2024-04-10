#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, q;

struct node {
    vector<int> rows;
    int cnt;
    node() : rows(vector<int>(n, 0)), cnt() {}
};

vector<bitset<3000>> rows(1);
vector<node> v;

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    v.pb(node());
    for(int i = 1; i <= q; i++) {
        int type;
        scanf("%d", &type);
        node cur = v.back();
        if(type == 1) {
            int i, j;
            scanf("%d%d", &i, &j);
            --i; --j;
            bitset<3000> t = rows[cur.rows[i]];
            if(t[j] == 0) {
                t.flip(j);
                cur.cnt++;
                cur.rows[i] = sz(rows);
                rows.pb(t);
            }
        } else if(type == 2) {
            int i, j;
            scanf("%d%d", &i, &j);
            --i; --j;
            bitset<3000> t = rows[cur.rows[i]];
            if(t[j] == 1) {
                t.flip(j);
                cur.cnt--;
                cur.rows[i] = sz(rows);
                rows.pb(t);
            }
        } else if(type == 3) {
            int i;
            scanf("%d", &i);
            --i;
            bitset<3000> t = rows[cur.rows[i]];
            for(int j = 0; j < m; j++)
                cur.cnt += (t[j] == 0) - (t[j] == 1);
            t.flip();
            cur.rows[i] = sz(rows);
            rows.pb(t);
        } else {
            int k;
            scanf("%d", &k);
            cur = v[k];
        }
        v.pb(cur);
        printf("%d\n", cur.cnt);
    }
}