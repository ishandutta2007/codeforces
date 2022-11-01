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

const int inf=2000000000;
const ld eps=1e-07;
int64 ans1, ans2;

int64 t1, t2, x1, x2, t;
ld besteps = inf;
int64 sum = 0;

void print() {
    cout << ans1 << " "<< ans2;
    exit(0);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin >> t1 >> t2 >> x1 >> x2 >> t;
    
    ans1 = ans2 = 0;
    if (t == t1) 
        ans1 = x1;
    if (t == t2) 
        ans2 = x2;
    if ((t == t1) || (t == t2))
      print();

    ld z = ld(t - t1) / ld(t2 - t);
    for (int64 i = 0; i <= x1; ++i) {
        int64 y2 = int64(z * ld(i));
        for (int64 y22 = y2 - 5; y22 <= y2 + 5; ++y22) {
            if( (y22 > 0) && (y22 <= x2)) {
                ld tekeps = ( ld((t1 * i) + (t2 * y22) ) / ld(i + y22) ) - ld(t)  ;
                if (tekeps < 0)
                    continue;
                if (tekeps < besteps) {
                    besteps = tekeps;
                    ans1 = i;
                    ans2 = y22;
                    sum  =ans1 + ans2;
                }
                if ((abs(tekeps - besteps) < eps) && (sum < (y22 + i))) {
                    ans1 = i;
                    ans2 = y22;
                    sum  =ans1 + ans2;
                }
            }
        }
    }

    for (int64 y22 = 1; y22 <= x2; ++y22){
            int64 i = 0;
            if( (y22 > 0) && (y22 <= x2)) {
                ld tekeps = ( ld((t1 * i) + (t2 * y22) ) / ld(i + y22) ) - ld(t)  ;
                if (tekeps < 0)
                    continue;
                if (tekeps < besteps) {
                    besteps = tekeps;
                    ans1 = i;
                    ans2 = y22;
                    sum  =ans1 + ans2;
                }
                if ((abs(tekeps - besteps) < eps) && (sum < (y22 + i))) {
                    ans1 = i;
                    ans2 = y22;
                    sum  =ans1 + ans2;
                }
            }
        }

    for (int64 i = 1; i <= x1; ++i) {
            int64 y22 = 0;
            if( (y22 >= 0) && (y22 <= x2)) {
                ld tekeps = ( ld((t1 * i) + (t2 * y22) ) / ld(i + y22) ) - ld(t)  ;
                if (tekeps < 0)
                    continue;
                if (tekeps < besteps) {
                    besteps = tekeps;
                    ans1 = i;
                    ans2 = y22;
                    sum  =ans1 + ans2;
                }
                if ((abs(tekeps - besteps) < eps) && (sum < (y22 + i))) {
                    ans1 = i;
                    ans2 = y22;
                    sum  =ans1 + ans2;
                }
            }
        }
    print();
    return 0;
}