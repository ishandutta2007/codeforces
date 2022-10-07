#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 1e6;
const int INF = 1e9;

int n, k;
int a[N];

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    for (int i = 0; i < n; i++)
        a[i]--;
    sort(a, a + n, greater < int > ()); 
    int ans = 0;
    for (int i = 0; i < n; i += k)
       ans += a[i] * 2; 
    printf("%d\n", ans);
}

void printAns() {
    
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}