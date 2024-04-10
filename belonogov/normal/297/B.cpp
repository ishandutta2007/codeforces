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

#define epr(...) fprintf(stderr, __VA_ARGS__

const int maxn = -1;
const int inf = 1e9;

map < int, int > q;


int main(){
   // freopen("in", "r", stdin);
   // freopen("out", "w", stdout);
    int n, m, k, x, ans;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++){
    scanf("%d", &x);
    q[x]++;
    }
    for(int i = 0; i < m; i++){
    scanf("%d", &x);
    q[x]--;
    }
    ans = 0;
    for(map < int, int > :: iterator it = q.end();true;){
    if (it == q.begin()) break;
    it--;

    ans += it->sc;
    if (ans > 0){
        printf("YES\n");
        return 0;
    }
    }
    printf("NO\n");
    
    return 0;
}