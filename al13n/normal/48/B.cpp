#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <complex>
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define linf SQ(1LL*iinf)
#define left asdleft
#define prev asdprev
#define eps 1e-8
#define y1 asdy1
#define y0 asdy0
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
#define dinf = 1e200

int n, m;
int ar[100][100];

int solve(int a, int b) {
    int min_trees = iinf;
    forn(i0, n - a + 1) {
        forn(j0, m - b + 1) {
            int trees = 0;
            forn(i, a)
                forn(j, b)
                    trees += ar[i0 + i][j0 + j];
            min_trees = min(min_trees, trees);
        }
    }
    return min_trees;
}

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    
    cin >> n >> m;
    forn(i, n)
        forn(j, m)
            cin >> ar[i][j];
    int a, b;
    cin >> a >> b;
    cout << min(solve(a, b), solve(b, a));
    
    return 0;
}