#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAXN = 100000;
const int MAXVAL = 10000;
int a[MAXN + 1], cnt[10 * MAXVAL], calcBits[10 * MAXVAL], n, k;

int countBits(int x) {
    int res = 0;
    while(x > 0) {
        res += x % 2;
        x /= 2;
    }
    return res;
}

ll fastSol() {
    memset(cnt, 0, sizeof(cnt));
    memset(calcBits, 0, sizeof(calcBits));
    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for(int i = 0; i <= 5 * MAXVAL; i++) {
        calcBits[i] = countBits(i);
    }
    ll ans = 0;
    for(int i = 0; i <= MAXVAL; i++) {
        for(int j = 0; j <= MAXVAL; j++) {
            if(calcBits[i ^ j] == k) {
                if(i != j)
                    ans += (ll)cnt[i] * cnt[j];
                else
                    ans += (ll)cnt[j] * (cnt[j] - 1);
            }
        }
    }
    return ans / 2;
}

ll stupSol() {
    memset(calcBits, 0, sizeof(calcBits));
    for(int i = 0; i <= MAXVAL; i++) {
        calcBits[i] = countBits(i);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(calcBits[a[i] ^ a[j]] == k) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cout << fastSol() << "\n";

    /*srand(time(NULL));
    for(int i = 0; ; i++) {
        n = 100000;
        k = rand() % 15;
        for(int j = 0; j < n; j++)
            a[j] = rand() % 10001;
        int st = clock();
        ll r1 = fastSol();
        int en = clock();
        cout << r1 << "\n";
        cout << (en - st + .0) / CLOCKS_PER_SEC << "\n";
    }*/
    return 0;
}