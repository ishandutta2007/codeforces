#include <bits/stdc++.h>
using namespace std;

const int MAX = 200010;
int n, k, a[MAX], tmp;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) { cin >> tmp; a[i] = a[i-1] ^ tmp; }
	for (int i = 0; i <= n; ++i) if (a[i] >= (1 << (k-1))) a[i] ^= (1 << k) - 1;
    sort(a, a+n+1);
    int64_t ans = 1ll * n * (n+1) / 2;
    int st = 0, en = -1;
    while (st <= n) {
        en = st;
        while (en + 1 <= n && a[en + 1] == a[st]) ++en;
        tmp = en - st + 1;
        int64_t a = tmp / 2, b = tmp - a;
        ans -= (1ll * a * (a-1) + 1ll * b * (b-1)) / 2;
        st = en + 1;
    }
    cout << ans;
}