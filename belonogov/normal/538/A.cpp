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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9;

string T = "CODEFORCES";

void read() {
    string s;
    cin >> s;
    int n = s.length();
    int len = (int)n - (int)T.size();
    if (len <= 0) {
        printf("NO\n");
        return;
    }
    for (int i = 0; i + len <= n; i++) {
        string p1 = s.substr(0, i);
        string p2 = "";
        if (i + len < n)
            p2 = s.substr(i + len, n - (i + len));
        assert(p1.size() + p2.size() == T.size());
        if (p1 + p2 == T) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");

}

void solve() {

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