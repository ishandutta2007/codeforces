#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 2e6;
const int inf = 1e9;

int a[maxn];
int b[maxn];
long long totalCntInv[100];
long long totalCntInv2[100];
long long cntInv[100];

void mergeSort(int l, int r, int k) {
    if (r - l == 1) return;
    mergeSort(l, (l + r) / 2, k - 1);
    mergeSort((l + r) / 2, r, k - 1);
    int cur1 = l;
    int cur2 = (l + r) / 2; 
    for (int i = l; i < r; i++) {
        if (cur1 < (l + r) / 2 && (cur2 == r || a[cur1] <= a[cur2])) {
            b[i] = a[cur1++];
        }
        else {
            b[i] = a[cur2++];
            cntInv[k] += (r - l) / 2 - (cur1 - l);
        }
    }
    for (int i = l; i < r; i++)
        a[i] = b[i];
    long long res = (r - l - 1) * 1ll * (r - l) / 2;
    for (int i = l; i < r; ) {
        int j = i;
        for (; i < r && a[i] == a[j]; i++);
        res -= (i - j - 1) * 1ll * (i - j) / 2;
    }
    totalCntInv2[k] += res;
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, m, t;
    long long ans;
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++)
        scanf("%d", &a[i]);
    //for (int i = 1; i <= n; i++)
        //totalCntInv[i] = (1 << (n - i)) * 1ll * (1 << (i - 1)) * (1 << (i - 1));
    //long long sum = 0;
    //for (int i = 0; i <= n; i++)
        //sum += totalCntInv[i];
    //assert(sum == (1 << n) * 1ll * ((1 << n) - 1) / 2);
    //for (int i = 0; i <= n; i++)
        //cerr << totalCntInv[i] << endl;
    //cerr << endl;
    /*int cnt = 0;
    for (int i = 0; i < (1 << n); i++)
        for (int j = i + 1; j < (1 << n); j++)
            cnt += a[j] < a[i];
    cerr << "cnt: " << cnt << endl;*/
    mergeSort(0, (1 << n), n);
/*    for (int i = 0; i <= n; i++)
        cerr << cntInv[i] << " ";
    cerr << endl;
    for (int i = 0; i <= n; i++)
        cerr << totalCntInv2[i] << " ";
    cerr << endl;*/

    for (int i = 1; i <= n; i++)
        totalCntInv[i] = totalCntInv2[i] - totalCntInv2[i - 1];
    //for (int i = 0; i <= n; i++)
        //cerr << totalCntInv[i] << " ";
    //cerr << endl;






    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        for (int j = t; j >= 0; j--)
            cntInv[j] = totalCntInv[j] - cntInv[j];
        ans = 0;
        for (int j = 0; j <= n; j++)
            ans += cntInv[j];
        printf("%lld\n", ans);
    }

    return 0;
}