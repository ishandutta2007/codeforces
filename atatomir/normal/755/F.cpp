#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1000011

int n, k, i, cnt, x, doub;
int p[maxN];
bool us[maxN];
vector<int> dims;

bool dp[maxN];
int rem[maxN];

bitset<maxN> B;

int get_min() {
    int i, j, cnt, pos, pos2, delta;
    int limit;

    dp[0] = true;

    sort(dims.begin(), dims.end());
    for (i = 0; i < dims.size(); i = j) {
        if (dims[i] > 500) break;

        for (j = i; j < dims.size(); j++)
            if (dims[j] != dims[i])
                break;

        if (dims[i] > k) break;

        cnt = j - i + 1;
        delta = dims[i];
        limit += delta * (cnt - 1);
        limit = min(limit, k);
        pos2 = 0;

        for (pos = 0; pos < delta; pos++)
                rem[pos] = cnt * dp[pos];
        for (pos = delta; pos <= limit; pos++, pos2++) {
            rem[pos] = rem[pos2] - 1;
            if (dp[pos]) {
                rem[pos] = cnt;
            } else {
                dp[pos] = (rem[pos] > 0);
            }
        }

        if (dp[k] == true)
            return k;
    }

    if (dp[k])
        return k;

    for (j = 0; j < k; j++) B[j] = dp[j];
    for (; i < dims.size(); i++) {
        if (dims[i] > k) break;
        B |= B << dims[i];

        if (B[k])
            return k;
    }

    if (B[k])
        return k;

    return k + 1;
}

int get_max() {
    for (auto e : dims)
        doub += e / 2;

    if (doub >= k)
        return 2 * k;
    else
        return min(n, doub * 2 + (k - doub));
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        cnt = 0;

        for (x = i; us[x] == false; us[x] = true, x = p[x], cnt++);

        dims.pb(cnt);
    }

    printf("%d %d\n", get_min(), get_max());


    return 0;
}