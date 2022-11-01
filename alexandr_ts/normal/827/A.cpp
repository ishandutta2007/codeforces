#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ld EPS = 1e-8;
const int M = 1e2 + 12;
const int MAX = 1e3 + 1;
const int N = 2e6 + 1;

string s[N];
int cnt[N];
vector <int> nums[N];

char s2[N];

struct seg {
    int l, r, num;
};

bool cmp(seg a, seg b) {
    return a.l < b.l;
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    int mx = 0;
    vector <seg> v;
    fr(i, n) {
        scanf("%s", s2);
        s[i] = s2;
        scanf("%d", &cnt[i]);
        fr(j, cnt[i]) {
            int x;
            scanf("%d", &x);
            x--;
            nums[i].pb(x);
            v.pb({x, x + (int)s[i].size() - 1, i});
            mx = max(mx, (int)s[i].size() + x);
        }
    }

    sort(v.begin(), v.end(), cmp);
    string ans;
    fr(i, mx)
        ans += 'a';
    int r = 0;
    fr(i, v.size()) {
        frab(j, max(r, v[i].l), v[i].r + 1)
            ans[j] = s[v[i].num][j - v[i].l];
        r = max(r, v[i].r + 1);
    }

    cout << ans << endl;

}