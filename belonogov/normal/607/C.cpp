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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2e6 + 10;
const long long INF = 1e9 + 19;

int n;
char s[N];
char t[N];
int p[N];

char rev(char ch) {
    if (ch == 'N') return 'S';
    if (ch == 'S') return 'N';
    if (ch == 'E') return 'W';
    if (ch == 'W') return 'E';
    assert(false);
}

void read() {
    scanf("%d", &n);
    scanf("%s%s", s, t);
}

void pref() {
    for (int i = 1; i < n; i++) {
        int x = p[i - 1];
        for (; x > 0 && t[x] != t[i]; x = p[x - 1]);
        //db2(i, x);
        if (t[x] == t[i])
            p[i] = x + 1;
    }
}

void solve() {
    n--;
    //db(n);
    reverse(t, t + n); 
    t[n] = '#';
    for (int i = 0; i < n; i++) 
        t[n + 1 + i] = rev(s[i]);
    n = n * 2 + 1;
    pref();
    if (p[n - 1] > 0) 
        puts("NO");
    else
        puts("YES");
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    //scanf("%s", t);
    ////db("here");
    //n = strlen(t);
    //pref();
    //for (int i = 0; i < n; i++)
        //cerr << p[i] << " ";
    //cerr << endl; 
    //return 0;
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}