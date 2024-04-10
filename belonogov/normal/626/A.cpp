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
const int N = -1;
const long long INF = 1e9 + 19;

int n;
string s;

void read() {
    cin >> n;
    cin >> s;
    map < pair < int, int >, int > q;
    q[mp(0, 0)] = 1;
    pair < int, int > x = mp(0, 0);
    int answer = 0;
    for (auto ch: s) {
        if (ch == 'U') x.fr++;   
        if (ch == 'D') x.fr--;   
        if (ch == 'R') x.sc++;   
        if (ch == 'L') x.sc--;   
        answer += q[x];
        q[x]++;
    }
    printf("%d\n", answer);

}

void solve() {

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
        }
    }
    else {
        stress();
    }

    return 0;
}