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
const int N = 1e5 + 10; 
const int INF = 1e9;
const int T = 51;

int n;
int p[N];
char a[N][T];
char b[N][T];
char * ans[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s %s", a[i], b[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]); 
        p[i]--;
    }
}


void solve() {
    int v = p[0];
    if (strcmp(a[v], b[v]) < 0)
        ans[0] = a[v];
    else
        ans[0] = b[v];

    bool flag = 1;
    for (int i = 1; i < n; i++) {
        char * mn, * mx;
        if (strcmp(a[p[i]], b[p[i]]) < 0) {
            mn = a[p[i]];
            mx = b[p[i]];
        }
        else {
            mn = b[p[i]];
            mx = a[p[i]];
        }
        if (strcmp(ans[i - 1], mn) < 0) {
            ans[i] = mn;
        } else if (strcmp(ans[i - 1], mx) < 0) {
            ans[i] = mx;
        } else {
            flag = 0;
            break;
        }
    }
    if (!flag)
        printf("NO\n");
    else
        printf("YES\n");
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