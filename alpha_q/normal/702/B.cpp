#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N];
map <int, int> M;
long long cnt = 0;

int main (int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i), M[a[i]]++;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 30; ++j) {
            if (a[i] < (1 << j)) {
                int now = (1 << j) - a[i];
                if (now == a[i]) {
                    if (M[now] > 1) cnt += (M[now] - 1);
                } else {
                    cnt += M[now];
                }
            }
        }
    }
    cnt >>= 1;

    printf("%lld\n", cnt);
	return 0;
}