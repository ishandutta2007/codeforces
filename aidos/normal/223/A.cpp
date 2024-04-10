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

char st[maxn], c[maxn];
int pos[maxn];
int d[maxn];
int pref[maxn];
int cur= 0;
int n;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%s\n", &c);
    n = strlen(c);

    int mx = 0, start = n, end = -1, balance = 0, cnt = 0;
    cur = 0;
    for(int i = 0; i < n; i++){
        cnt += (c[i] == ']');
        if(c[i] == ']'){
            if( cur == 0 || st[cur-1] != '['){
                d[i] = -1;
                cur = 0;
            }
            else {
                cur--;
                if( cur == 0) {
                    if( pos[cur] > 0) d[i] = d[pos[cur] - 1];
                    else d[i] = -1;
                    if( d[i] == -1) d[i] = pos[cur];
                }else d[i] = pos[cur-1]+1;
            }
        }
        else if( c[i] == ')'){
            if( cur == 0 || st[cur-1] != '('){
                d[i] = -1;
                cur = 0;
            }
            else {
                cur--;
                if( cur == 0) {
                    if( pos[cur] > 0) d[i] = d[pos[cur] - 1];
                    else d[i] = -1;
                    if( d[i] == -1) d[i] = pos[cur];
                }
                else d[i] = pos[cur-1]+1;
            }
            
        }
        else {
            st[cur] = c[i];
            pos[cur] = i;
            d[i] = -1;
            cur++;
        }
        pref[i] = cnt;
    }
    for(int i = 0; i < n; i++){
        int x = d[i];
        int cc = pref[i];
        if(x == -1 || cc == 0) continue;
        if( x > 0 ) cc -= pref[x-1];
        if(mx < cc) {
            mx = cc;
            start = d[i];
            end = i;
        }
    }
    cout << mx << endl;
    for(int i = start; i <= end; i++){
        cout << c[i];
    }
    

     
    

    
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}