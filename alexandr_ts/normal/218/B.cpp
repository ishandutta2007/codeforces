#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, n) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e5 + 1;

int a[N], b[N];

int main() {
    int n, m;
    cin >> n >> m;
    fr(i, m)
        cin >> a[i];
    int mn = 0;
    int n1 = n;
    int cur = 0;
    sort(a, a + m);
    fr(i, n) {
        cur = 0;
        while (cur < n1 && cur < a[i])
            mn += a[i] - cur++;
        n1 -= a[i];
    }
    multiset <int> st;
    fr(i, m)
        st.insert(-a[i]);
    int mx = 0;
    fr(i, n) {
        auto it = st.begin();
        int x = *it;
        mx -= x;
        st.erase(it);
        if (-x > 0)
            st.insert(x + 1);
    }

    cout << mx << " " << mn << endl;





}