#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 5;
const int M = 10 * 1000 * 1000 + 1;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e14 + 10;
const ld EPS = 1e-10;

int a[N];
int c[M];

pair <int, int> b[N];

//bool cmp(tn a, tn b) {
//    return a.v > b.v;
//}

int answer[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    fr(i, n)
        scanf("%d", &a[i]);
        //cin >> a[i];
    sort(a, a + n);
    fr(i, m) {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }
    sort(b, b + m);
    reverse(b, b + m);
    fr(i, M)
        c[i] = k;

    int cur = n - 1;
    for (int i = M - 1; i >= 0; i--) {
        while (cur >= 0 && a[cur] >= i && c[i])
            c[i]--, cur--;
    }
    if (cur != -1) {
        cout << -1;
        return 0;
    }
    vector <int> ans;
    int posa = 0;
    cur = 0;
    for (int i = M - 1; i >= 0; i--) {
        while (c[i] && cur < m && b[cur].first >= i) {
            //ans.pb(b[cur].n + 1);
            answer[posa++] = b[cur].second + 1;
            c[i]--, cur++;
        }
    }
    cout << posa << endl;
    fr(i, posa)
        printf("%d ", answer[i]);// << answer[i] << " ";
}