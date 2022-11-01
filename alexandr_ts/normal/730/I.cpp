#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 1e6 + 10;
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 5e5 + 10;

struct pers {
    int a, b, num;
} a[N];

bool cmpa(pers a, pers b) {
    if (a.a == b.a) return a.num < b.num;
    return a.a > b.a;
}

bool cmpb(pers a, pers b) {
    if (a.b == b.b) return a.num < b.num;
    return a.b > b.b;
}

bool cmpdif(pers a, pers b) {
    if (a.a - a.b == b.a - b.b) return a.num < b.num;
    return a.a - a.b > b.a - b.b;
}

ll calc(vector <pers> v, int p, int s) {
    sort(v.begin(), v.end(), cmpdif);
    ll ans = 0;
    fr(i, p)
        ans += v[i].a;
    frab(i, p, s + p)
        ans += v[i].b;
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, p, s;
    cin >> n >> p >> s;
    assert(p >= 1 && s >= 1 && s + p <= n && n <= 3000 && n >= 2);
    fr(i, n)
        cin >> a[i].a;
    fr(i, n)
        cin >> a[i].b;
    fr(i, n)
        a[i].num = i;

    ll ans = -1;
    vector <pers> answer;

    frab(k, p, s + p + 1) {
        sort(a, a + n, cmpa);
        sort(a + k, a + n, cmpb);
        vector <pers> v(p + s);
        fr(i, p + s)
            v[i] = a[i];
        ll tmp = calc(v, p, s);
        if (tmp > ans)
            ans = tmp, answer = v;
    }

    cout << ans << endl;
    assert(ans > 0);
    assert(answer.size() == p + s);
    sort(answer.begin(), answer.end(), cmpdif);
    fr(i, p)
        cout << answer[i].num + 1 << " ";
    cout << endl;
    frab(i, p, answer.size())
        cout << answer[i].num + 1 << " ";
    fr(i, p + s)
        frab(j, i + 1, p + s)
            assert(answer[i].num != answer[j].num);
}