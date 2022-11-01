#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 10;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

struct tn1 {
    int x, num, ans;
};

int a[N];
tn1 b[N];

set <int> st;
vector <int> ans;

bool cmp(tn1 a, tn1 b) {
    return a.x < b.x || a.x == b.x && a.num < b.num;
}

bool cmp2(tn1 a, tn1 b) {
    return a.num < b.num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    fr(i, m) {
        cin >> b[i].x;
        b[i].num = i;
    }
    sort(b, b + m, cmp);
    b[m].x = n;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = b[i].x; j <= b[i + 1].x; j++)
            st.insert(a[j - 1]);
        b[i].ans = st.size();
    }
    sort(b, b + m, cmp2);
    fr(i, m)
        cout << b[i].ans << endl;
}