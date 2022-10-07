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
const int INF = 1e9 + 19;

struct Event {
    int x, y;
    string s;
};

int n, k;
vector < Event > b;
long long dp[N][N];
int val[N];


void read() {
    scanf("%d%d", &n, &k);
    b.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i].x >> b[i].s >> b[i].y;
        b[i].x--;
        b[i].y--;
    }
}

void solve() {
    dp[0][0] = 1;
    for (int sum = 0; sum < n * 2; sum += 2) {
        for (int l = 0; l <= sum; l++) {
            int r = sum - l;
            for (int cntL = 0; cntL <= 2; cntL++) {
                memset(val, -1, sizeof(val));
                for (int i = 0; i < l; i++)
                    val[i] = 0; 
                for (int i = 0; i < cntL; i++)
                    val[l + i] = 1;
                for (int i = 0; i < r; i++)
                    val[n * 2 - 1 - i] = 0;
                for (int i = 0; i < 2 - cntL; i++)
                    val[n * 2 - 1 - r - i] = 1;

                for (int i = l + cntL; i <= n * 2 - 1 - r - (2 - cntL); i++)
                    val[i] = 2; 

                for (int i = 0; i < n * 2; i++)
                    assert(val[i] != -1);
                bool flag = 1;
                for (int i = 0; i < k; i++) {
                    if (val[b[i].x] != 1 && val[b[i].y] != 1) 
                        continue;
                    if (b[i].s == "=")
                        flag &= val[b[i].x] == val[b[i].y]; 
                    else if (b[i].s == "<")
                        flag &= val[b[i].x] < val[b[i].y];
                    else if (b[i].s == ">")
                        flag &= val[b[i].x] > val[b[i].y];
                    else if (b[i].s == "<=")
                        flag &= val[b[i].x] <= val[b[i].y];
                    else if (b[i].s == ">=")
                        flag &= val[b[i].x] >= val[b[i].y];
                    else
                        assert(false);
                }
                if (flag)
                    dp[l + cntL][r + 2 - cntL] += dp[l][r];
            }
        }
    } 
    //for (int i = 0; i <= n * 2; i++) {
        //for (int j = 0; j <= n * 2; j++)
            //cerr << dp[i][j] << " ";
        //cerr << endl;
    //}
    long long answer = 0;
    for (int i = 0; i <= n * 2; i++)
        answer += dp[i][n * 2 - i];
    assert(answer % 3 == 0);
    cout << answer / 3 << endl;
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