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
const int N = 1000 + 10;
const int INF = 1e9;

int n, p;
int a[N];
char s[N];


void read() {
    scanf("%d%d", &n, &p);
    scanf("%s", s);
}

void printAns() {
    for (int i = 0; i < n; i++)
        printf("%c", a[i] + 'a');
    printf("\n");
}

void solve() {
    for (int i = 0; i < n; i++)
        a[i] = s[i] - 'a';
    for (int i = n - 1; i >= 0; i--) {
        int res = -1;
        for (int j = a[i] + 1; j < p; j++) {
            bool flag = 1;
            if (i >= 1 && a[i - 1] == j)
                flag = 0;
            if (i >= 2 && a[i - 2] == j)
                flag = 0;
            if (flag) {
                res = j; 
                break;
            }
        }
        if (res != -1) {
            a[i] = res;
            for (int k = i + 1; k < n; k++)
                for (int j = 0; j < p; j++) {
                    bool flag = 1;
                    if (k >= 1 && a[k - 1] == j)
                        flag = 0;
                    if (k >= 2 && a[k - 2] == j)
                        flag = 0;
                    if (flag) {
                        a[k] = j;
                        break;
                    }
                } 
            printAns();
            return;
        } 
    } 
    printf("NO\n");
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
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}