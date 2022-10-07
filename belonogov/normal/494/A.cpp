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
#define dbg(x) { cerr << #x << " = " << x << endl; }
const int N = 2e5 + 10;
const int INF = 1e9;

int n;
char s[N];

void read() {
    scanf("%s", s);
    n = strlen(s);
}

void solve() {
    int pos = -1;
    int b = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            pos = i;
            cnt++;
            s[i] = ')';
        }
        if (s[i] == '(')
            b++;
        if (s[i] == ')')
            b--;
        if (b < 0){
            printf("-1\n");
            exit(0);
        } 
    }
    for (int i = n - 1; i >= pos + 1; i--)
        s[i + b] = s[i];
    for (int i = pos + 1; i <= pos + b; i++)
        s[i] = ')';
    n += b;
    int t = 0;
    for (int i = 0; i < n; i++)  {
        if (s[i] == '(') t++;
        if (s[i] == ')') t--;
        if (t < 0) {
            printf("-1\n");
            exit(0);
        } 
    }
    for (int i = 0; i < cnt - 1; i++)   
        printf("1\n");
    printf("%d\n", b + 1);
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