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
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

int a[N];

multiset <int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n, x, ans = 0;
    cin >> n;
    cin >> x;
    fr(i, n - 1) {
        cin >> a[i];
        st.insert(-a[i]);
    }

   while (x <= abs(*st.begin())) {
        //for(auto it = st.begin(); it != st.end(); it++)
           // cout << *it << " ";cout << endl;//cout << *st.begin() << endl;
        x++, ans++;
        int tmp = *(st.begin());
        st.erase(st.begin());
        st.insert(tmp + 1);
    }
    cout << ans;
}