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

const int maxn = 1e6;
const int inf = 1e9;

char s[maxn];
char stack[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, cur = 0;
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++){
        if (cur == 0 || stack[cur - 1] != s[i])
            stack[cur++] = s[i];
        else
            cur--;
    }
//  cerr << cur << endl;
    if (cur == 0)
        printf("Yes\n");
    else
        printf("No\n");
 
 
    return 0;
}