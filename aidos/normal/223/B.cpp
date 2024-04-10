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
const int maxn = (int) 2e5 + 10;

using namespace std;

char c[maxn], d[maxn];
int n, m;
int pos1[maxn], pos2[maxn];
vector < int > v[27];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%s %s\n", &c, &d);
    n = strlen(c);
    m = strlen(d);
    int cur = 0, cur1;

    for(int i = 0; i < m; i++){
        v[d[i] -'a'].pb(i);
    }

    for(int i = 0; i < n; i++){
        if(cur != m && d[cur] == c[i]){
            cur++;
        }
        pos1[i] = cur;
    }
    cur = m-1;
    for(int i = n-1; i >=0; i--){
        if(cur >=0 && d[cur] == c[i]){
            cur--;
        }
        pos2[i] = cur;
    }
    if( cur > -1){
        cout << "No";
        return 0;
    }

    for(int i = 0; i < n; i++){
        int pos = lower_bound(v[c[i]-'a'].begin(), v[c[i]-'a'].end(), pos2[i]) - v[c[i]-'a'].begin();
        if( pos == v[c[i]-'a'].size() || v[c[i]-'a'][pos] > pos1[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";




    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}