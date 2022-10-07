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
const int N = 1e5; 
const long long INF = 1e9 + 19;

int n;
string s[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
}

void solve() {
    int minDist = 13;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int dist = 0;
            for (int k = 0; k < 6; k++)
                dist += s[i][k] != s[j][k];
            minDist = min(minDist, dist);
        }
    cout << (minDist - 1) / 2 << endl;

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