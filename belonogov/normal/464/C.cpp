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
const int N = 1e6;
const int INF = 1e9;
const int base = 10;
const int MOD = 1e9 + 7;

char s[N];
string t[N];
char ch[N];
char data[N * 3];
int n, m;
int cur;
long long st[base];
long long b[base];

void read() {
    ch[0] = '0';
    cin >> t[0];
    scanf("%d\n", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%c->", &ch[i]);
        getline(cin, t[i]);
    }
    m++;
}

void solve() {
    for (int i = 0; i < base; i++) {
        st[i] = 10;
        b[i] = i;
    }
    //cerr << "m: " << m << endl;
    //for (int i = 0; i < m; i++)
        //cerr << ch[i] << "->" << t[i] << endl;
    for (int i = m - 1; i >= 0; i--) {
        long long stNew = 1;
        long long bNew = 0;
        for (int j = (int)t[i].length() - 1; j >= 0; j--) {
            int r = t[i][j] - '0';
            bNew = (bNew + stNew * b[r]) % MOD;
            stNew = (stNew * st[r]) % MOD;
        }
        int r = ch[i] - '0';
        st[r] = stNew;
        b[r] = bNew;
    }
}

void printAns() {
    printf("%lld\n", b[0]);
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