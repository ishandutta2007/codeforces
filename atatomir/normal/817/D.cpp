#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1000011

int n, i;
ll a[maxN];
ll ans;

int le[maxN], ri[maxN];
vector<int> st;

void solve() {
    int i;
    a[0] = a[n + 1] = 1LL << 60;

    st = {0};
    for (i = 1; i <= n; i++) {
        while (a[st.back()] < a[i]) st.pop_back();
        le[i] = st.back();
        st.pb(i);
    }

    st = {n + 1};
    for (i = n; i >= 1; i--) {
        while (a[st.back()] <= a[i]) st.pop_back();
        ri[i] = st.back();
        st.pb(i);
    }

    for (i = 1; i <= n; i++)
        ans += a[i] * (ri[i] - i) * (i - le[i]);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);

    solve();
    for (i = 1; i <= n; i++) a[i] *= -1;
    solve();

    printf("%lld", ans);

    return 0;
}