#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = 1e6;
const int inf = (int)1e9;


int a[maxn];
int sum[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, t, cur, ans;
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + a[i];
    cur = 0;
    ans = 0;
    for(int i = 0; i < n; i++){
        for(; cur < n && sum[cur] - sum[i] <= t; cur++);
        if (sum[cur] - sum[i] > t) cur--;
        ans = max(ans, cur - i);
    }
    cout << ans << endl;

    return 0;
}