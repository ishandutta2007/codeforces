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

#define equal equalll
#define less lesss
const int N = 111;
const int INF = 1e9;

int n;
int a[N];
int b[N];
char s[N][N];
vector < int > answer;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    bool flag = 1;
    for (;flag;) {
        flag = 0;
        for (int j = 0; j < n; j++)
            if (b[j] == a[j]) {
                answer.pb(j);
                for (int i = 0; i < n; i++)
                    b[i] += s[j][i] - '0';
                flag = 1;
                break;
            }
    }
    printf("%d\n", (int)answer.size());
    for (auto x: answer)
        printf("%d ", x + 1);
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