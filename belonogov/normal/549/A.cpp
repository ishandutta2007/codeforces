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

int n, m;
char s[N][N];

void read() { 
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}

void solve() {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++) {
            vector < char > tmp;
            tmp.pb(s[i][j]);
            tmp.pb(s[i + 1][j]);
            tmp.pb(s[i][j + 1]);
            tmp.pb(s[i + 1][j + 1]);
            sort(tmp.begin(), tmp.end()); 
            if (tmp[0] == 'a' && tmp[1] == 'c' && tmp[2] == 'e' && tmp[3] == 'f')
                cnt++;
        }
    cout << cnt << endl;
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