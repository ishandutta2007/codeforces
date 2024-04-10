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
const int N = 111;
const int INF = 1e9 + 19;

char s[N][N];
bool use[N];
int n, m;


void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}

void solve() {
    int answer = 0;
    for (int j = 0; j < m; j++) {
        bool flag = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (use[i]) continue;
            if (s[i][j] > s[i + 1][j])
                flag = 1;
        }
        if (flag) {
            answer++;
        }
        else {
            for (int i = 0; i + 1 < n; i++) {
                if (s[i][j] < s[i + 1][j])
                    use[i] = 1;
            }
        }

    }
    cout << answer << endl;


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