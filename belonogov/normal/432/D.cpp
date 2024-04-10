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


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 1e5 + 10;
const int INF = 1e9;


char s[N];
int z[N];
int pref[N];
int a[N];

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n;
    scanf("%s", s);
    n = strlen(s);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        int res = 0;
        if (r > i)
            res = min(r - i, z[i - l]);
        for (; i + res < n && s[i + res] == s[res]; res++);
        z[i] = res;
        if (i + res > r) {
            r = i + res;
            l = i;
        }
    }
    pref[n]++;
    for (int i = 1; i < n; i++)
        pref[z[i]]++;
    for (int i = n; i > 0; i--)
        a[i] = a[i + 1] + pref[i];
    vector < pair < int, int > > answer;
    for (int i = 1; i < n; i++)
        if (z[n - i] >= i) {
            answer.pb(mp(i, a[i]));
        }
    answer.pb(mp(n, 1));
    printf("%d\n", (int)answer.size());
    for (int i = 0; i < (int)answer.size(); i++)
        printf("%d %d\n", answer[i].fr, answer[i].sc);
    return 0;
}