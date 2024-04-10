#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = -1;
const int inf = 1e9;

vector < pair < long long, long long > > pos;
string s;

int main(){
 //   freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    long long a, b, x, y, a1, b1, n;
    cin >> a >> b;
    cin >> s;
    n = s.length();
    x = y = 0;
 //   epr("1\n");
 //   cerr << n << endl;
    for(int i = 0; i < n; i++){
    //    epr("i %d\n", i);
        pos.pb(mp(x, y));
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
    }
   // epr("2\n");
    for(int i = 0; i < (int)pos.size(); i++){
      //  epr("i %d\n", i);
        a1 = a - pos[i].fr;
        b1 = b - pos[i].sc;
        if (x == 0){
            if (a1 != 0) continue;
            if (y == 0){
                if (b1 != 0) continue;
                printf("Yes\n");
                return 0;
            }
            if (b1 % y == 0 && b1 / y >= 0){
                printf("Yes\n");
                return 0;
            }
            continue;
        }
        if (a1 % x == 0 && a1 / x >= 0 && y * (a1 / x) == b1){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}