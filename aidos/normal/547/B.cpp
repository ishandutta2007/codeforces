#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;


int a[200200];
int t[200100];
int st[200200];
int sz=0;
int n;

void upd(int x, int c){
    if(t[x] < c) t[x] = c;
    //cout << x << "  " << c << endl;
}




int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n );
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++){
        while(sz > 0 && a[st[sz-1]] >= a[i]) {
            if(sz > 1) upd(i-st[sz-2] - 2, a[st[sz-1]]);
            else upd(i-1, a[st[sz-1]]);
            sz--;
        }
        st[sz] = i;
        sz++;
    }
    while(sz > 1){
        upd(n - 2 - st[sz-2], a[st[sz-1]]);
        sz--;
    }
    upd(n-1, a[st[sz-1]]);
    int last = 0;
    for(int i = n-1; i >=0; i--){
        if(t[i] < last) t[i] = last;
        last = t[i];
    }
    for(int i = 0; i<n; i++)
        printf("%d ", t[i]);
    printf("\n");
    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}