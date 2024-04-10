#include <iostream>

using namespace std;

const int MAXN = 500 * 1000 + 5;
int a[MAXN], cnt[MAXN], div[MAXN];
char c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    div[1] = 1;
    for(int i = 2; i < MAXN; i++) {
        div[i] = 1;
        for(int j = 2; j * j <= i; j++)
            if(!(i % j)) {
                div[i] = div[i / j] + 1;
                break;
            }
    }
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int b = 1;
        for(int j = 2; j * j <= a[i]; j++)
            if(!(a[i] % j)) {
                b *= j;
                while(!(a[i] % j))
                    a[i] /= j;
            }
        if(a[i] > 1)
            b *= a[i];
        a[i] = b;
    }
    long long ans = 0;
    int k = 0;
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;
        if(c[x]) {
            k--;
            for(int j = 1; j * j <= a[x]; j++) {
                if(!(a[x] % j)) {
                    cnt[j]--;
                    if(j > 1)
                        ans -= ((div[j] & 1)? 1 : -1) * cnt[j];
                    int jj = a[x] / j;
                    if(jj != j) {
                        cnt[jj]--;
                        ans -= ((div[jj] & 1)? 1 : -1) * cnt[jj];
                    }
                }
            }
        }
        else {
            k++;
            for(int j = 1; j * j <= a[x]; j++) {
                if(!(a[x] % j)) {
                    if(j > 1)
                        ans += ((div[j] & 1)? 1 : -1) * cnt[j];
                    cnt[j]++;
                    int jj = a[x] / j;
                    if(jj != j) {
                        ans += ((div[jj] & 1)? 1 : -1) * cnt[jj];
                        cnt[jj]++;
                    }
                }
            }
        }
        c[x] = !c[x];
        cout << (long long)k * (k - 1) / 2 - ans << '\n';
    }
    return 0;
}