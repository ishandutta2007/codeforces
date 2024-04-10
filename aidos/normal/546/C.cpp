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


set < pair < queue < int >, queue < int > > > S;
int n, n1, n2;
queue < int > q1, q2;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    scanf("%d", &n1);
    for(int i = 0, x; i < n1; i++){
        scanf("%d", &x);
        q1.push(x);
    }
    scanf("%d", &n2);
    for(int i = 0, x; i < n2; i++){
        scanf("%d", &x);
        q2.push(x);
    }
    int cnt= 0;
    while(S.find(mp(q1, q2)) == S.end()){
        S.insert(mp(q1, q2));
        cnt++;
        int x1 = q1.front();
        q1.pop();
        int x2 = q2.front();
        q2.pop();
        if(x1 < x2){
            q2.push(x1);
            q2.push(x2);
        }
        else {
            q1.push(x2);
            q1.push(x1);
        }
        if(q1.empty()) {
            cout << cnt << " " << 2 << endl;
            return 0;
        }
        if(q2.empty()) {
            cout << cnt << " " << 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}