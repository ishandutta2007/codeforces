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
const int maxn = 1e6 + 10;
const int inf = 1e9;

int use[maxn];
vector < pair < int, int > > b;
vector < int > ans;

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int s = 1e6;
    int n, cnt = 0, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x); x--;
        use[x] = 1;
    }
    for (int i = 0; i < s / 2; i++) {
        int j = s - i - 1;
        if ((use[i] ^ use[j]) == 1) {
            if (use[i])
                ans.pb(j);
            else
                ans.pb(i);
            continue;
        }
        if (use[i] == 0)
            b.pb(mp(i, j)); 
        else 
            cnt++;
    }
    assert((int)b.size() >= cnt);
    for (int i = 0; i < cnt; i++) {
        ans.pb(b[i].fr);
        ans.pb(b[i].sc);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%d ", ans[i] + 1); 
    return 0;
}