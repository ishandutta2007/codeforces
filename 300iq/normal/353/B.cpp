#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 100 + 7;
bool used[MAXN];
int a[MAXN * 2];
int col[MAXN * 2];
int ct[MAXN * 2];

int main() {
    srand(time(NULL));
    if (1) {
        memset(col, 0, sizeof col);
        memset(ct, 0, sizeof ct);
        memset(used, 0, sizeof used);
        int n = 6;
        scanf("%d", &n);
        n *= 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            //a[i] = 1 + rand() % 3;
            scanf("%d", &a[i]);
            if (!used[a[i]]) {
                used[a[i]] = 1;
                cnt++;
                col[i] = 1;
            } else {
                col[i] = 2;
                ct[a[i]]++;
            }
        }
        /*
        int dumbass = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (bit(mask) != n / 2) continue;
            set <int> f1, f2;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    f1.insert(a[i]);
                } else {
                    f2.insert(a[i]);
                }
            }
            dumbass = max(dumbass, (int) f1.size() * (int) f2.size());
        }
        */
        for (int i = 0; i < n && cnt * 2 > n; i++) {
            if (col[i] == 1 && ct[a[i]] == 0) {
                col[i] = 2;
                ct[a[i]]++;
                cnt--;
            }
        }
        for (int i = 0; i < n && cnt * 2 > n; i++) {
            if (col[i] == 1) {
                col[i] = 2;
                cnt--;
            }
        }
        for (int i = 0; i < n && cnt * 2 < n; i++) {
            if (col[i] == 2 && ct[a[i]] > 1) {
                col[i] = 1;
                cnt++;
                ct[a[i]]--;
            }
        }
        for (int i = 0; i < n && cnt * 2 < n; i++) {
            if (col[i] == 2) {
                col[i] = 1;
                cnt++;
            }
        }
        set <int> f1, f2;
        for (int i = 0; i < n; i++) {
            if (col[i] == 1) {
                f1.insert(a[i]);
            } else {
                f2.insert(a[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (col[i] == 1 && col[j] == 2) {
                    set <int> a1, b1;
                    swap(col[i], col[j]);
                    for (int k = 0; k < n; k++) {
                        if (col[k] == 1) {
                            a1.insert(a[k]);
                        } else {
                            b1.insert(a[k]);
                        }
                    }
                    //cout << a1.size() << ' ' << b1.size() << endl;
                    if ((int) a1.size() * (int) b1.size() > (int) f1.size() * (int) f2.size()) {
                        f1 = a1, f2 = b1;
                        continue;
                    } else {
                        swap(col[i], col[j]);
                    }
                }
            }
        }
        printf("%d\n", (int) f1.size() * (int) f2.size());
        for (int i = 0; i < n; i++) {
            printf("%d ", col[i]);
        }
        puts("");
    }
}