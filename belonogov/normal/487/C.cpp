#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const int INF = 1e9 + 19;

int n;
int use[N];
int answer[N];
int b[N];
int tmr;
int deg[N];
int rev[N];

void read() {
    scanf("%d", &n);
}

void solve() {
    if (n == 1) {
        puts("YES\n1");
        return;
    }
    if (n == 4) {
        printf("YES\n");
        puts("1");
        puts("3");
        puts("2");
        puts("4");
        return;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            puts("NO");
            return;
        }
    }
    answer[n - 1] = n;
    int root = -1;
    for (int i = 1; i < n; i++) {
        tmr++;
        int h = 1;
        bool flag = 1;
        for (int j = 0; j < n - 1; j++) {
            //db(h, j);
            if (use[h] == tmr) {
                flag = 0;
                break;
            }
            deg[h] = j;
            rev[j] = h;
            use[h] = tmr;
            h = (h * 1ll * i) % n;
        }
        if (flag) {
            root = i;
            break;
        }
    }   
    assert(root != -1);
    b[0] = 0;
    int cur1 = n - 2;
    int cur2 = 2;
    for (int i = 1; i < n - 1; i++)
        if (i % 2 == 1) {
            b[i] = cur1;
            cur1 -= 2;
        }
        else {
            b[i] = cur2;
            cur2 += 2;
        }
    //for (int i = 0; i < n; i++)
        //cerr << b[i] << " ";
    //cerr << endl;
    //db(root);
    for (int i = 0; i < n - 1; i++)
        answer[i] = rev[b[i]];


    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", answer[i]);

    set < int > q;
    int r = 1;
    for (int i = 0; i < n; i++) {
        r = answer[i] * 1ll * r % n;
        q.insert(r);
    }
    assert((int)q.size() == n);

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
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
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