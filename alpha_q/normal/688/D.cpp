#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, k, c[N];
map <int, int> PowOfK;
map <int, int> PowInLCM;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", c + i);

    if (k == 1) {
        printf("Yes\n");
        return 0;
    }

    while ((k & 1) == 0) {
        PowOfK[2]++;
        k >>= 1;
    }

    for (int i = 3; i * i <= k; i += 2) {
        while (k % i == 0) {
            PowOfK[i]++;
            k /= i;
        }
    }

    if (k > 1) PowOfK[k]++;

    for (auto it : PowOfK) {
        //cout << it.first << " " << it.second << endl;
        PowInLCM[it.first] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (auto it : PowOfK) {
            int p = it.first, e = it.second;
            int exp = 0;
            while (c[i] % p == 0) {
                exp++;
                c[i] /= p;
            }
            PowInLCM[p] = max(PowInLCM[p], exp);
        }
    }

    for (auto it : PowOfK) {
        int p = it.first, e = it.second;
        if (PowInLCM[p] < e) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}