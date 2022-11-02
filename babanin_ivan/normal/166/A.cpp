#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

bool comp(pair <int, int> a, pair <int, int> b) {
    if (a.first > b.first)
        return true;
    if (a.first < b.first)
        return false;
    if (a.second < b.second)
        return true;
    return false;
}

int n, k;
pair <int, int> a[2000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    for (int c = 0; c < n; ++c) {
        scanf("%d %d", &a[c].fir, &a[c].sec);
    }
    sort(a, a + n, comp);
    int t = 0;
    int i = 0;
    int ans = 0;
    while (i < n) {
        //++t;
        int j = i;
        while ((j < n) && (a[i] == a[j]))
            ++j;
        t += j - i;
        if (t >= k) {
            ans = j - i;
            break;
        }

        i = j;
    }
    cout << ans << endl;
    return 0;
}