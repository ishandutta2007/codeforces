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

const int maxn = -1;
const int inf = 1e9;


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, k, ans, a;
    cin >> n >> m >> k;
    while (n --> 0){
        scanf("%d", &a);
        if (a == 1){
            if (m > 0)
                m--;
            else
                ans++;
        }
        if (a == 2){
            if (k > 0)
                k--;
            else
                if (m > 0)
                    m--;
                else
                    ans++;
        }
    }
    cout << ans << endl;
 
    return 0;
}