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

const int maxn = 1e5;
const int inf = 1e9;

char s[maxn];

int solve(){
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    for(int i = 0; i < n; i++)
    ans += (s[i] == '1');
    return ans;    
}


int main(){
//     freopen("in", "r", stdin);
   // freopen("out", "w", stdout);
    int r1 = solve();
    int r2 = solve();
    if (r1 % 2 == 1)
    r1++;
    if (r1 >= r2)
    printf("YES\n");
    else
    printf("NO\n");
    
    return 0;
}