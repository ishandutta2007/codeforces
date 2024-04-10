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
const int N = 1e6;
const int INF = 1e9 + 19;


char s[N];
char t[N];
char tmp[N];
int n;

void read() {
    scanf("%s%s", s, t);
    n = strlen(s);
}

int strcmp1(char * s, char * t, int len) {
    int cur = 0;
    for (; cur < len && s[cur] == t[cur]; cur++);
    if (cur == len) return 0;
    if (s[cur] < t[cur])
        return -1;
    return 1;
}


void lexMin(char * s, int n) {
    if (n % 2 == 1) return;
    lexMin(s, n / 2);
    lexMin(s + n / 2, n / 2);
    if (strcmp1(s, s + n / 2, n / 2) > 0) {
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n / 2 + i]);
    }
}

void solve() {
    lexMin(s, n);
    lexMin(t, n);
    cout << ((strcmp1(s, t, n) == 0)? "YES": "NO") << endl;
    //cout << s << endl;
    //cout << t << endl;
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