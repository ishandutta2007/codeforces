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
const int N = 1e3;
const int MAXVAL = 30;
const int INF = 1e9;

struct node {
    int a, b, id;
};

int n;
node s[N];
int cntUse[N];
int b[N];
int ans, res;
int gcd[100][100];
int p[N];

bool cmpA(node a, node b) {
    return a.a < b.a;
}

bool cmpId(node a, node b) {
    return a.id < b.id;
}

void read() {
    if (scanf("%d", &n) != 1) exit(0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i].a);
        s[i].id = i;
    }
}

void rec(int pos, int k) {  
    if (res >= ans) {
        return;
    }
    if (n == pos) {
        if (res < ans) {
            for (int i = 0; i < n; i++)
                s[i].b = b[i];
            ans = res;
        }
        return;
    }
    for (int i = k; i < MAXVAL * 2; i++) {
        if (cntUse[i] > 0) 
            continue;   
        for (int j = 1; j < MAXVAL * 2; j++)
            cntUse[j] += gcd[i][j];
        b[pos] = i;
        res += abs(i - s[pos].a);
        rec(pos + 1, i);
        res -= abs(i - s[pos].a);
        for (int j = 1; j < MAXVAL * 2; j++)
            cntUse[j] -= gcd[i][j];

        if (p[i] && s[pos].a <= i)
            break;
    } 
}

int getGCD(int a, int b) {
    return (b != 0)? getGCD(b, a % b): a;
}

void solve() {
    for (int i = 2; i < MAXVAL * 2; i++) {
        bool flag = 1;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0) 
                flag = 0;
        p[i] = flag;
    } 
    memset(cntUse, 0, sizeof(cntUse));
    for (int i = 1; i < MAXVAL * 2; i++)
        for (int j = 1; j < MAXVAL * 2; j++)
            gcd[i][j] = getGCD(i, j) > 1;
    sort(s, s + n, cmpA); 
    ans = INF;
    res = 0;
    rec(0, 1); 
}

void printAns() {
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    //cerr << "ans: " << ans << endl;
    sort(s, s + n, cmpId);
    for (int i = 0; i < n; i++)
        printf("%d ", s[i].b);
    printf("\n");
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
        }
    }
    else {
        stress();
    }

    return 0;
}