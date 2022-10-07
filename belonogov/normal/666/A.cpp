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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 11111;
const long long INF = 1e9 + 19;

string s;

void read() {
    cin >> s;
}

int dp[N][2];

void solve() {
    reverse(s.begin(), s.end());
    for (int i = 0; i < 5; i++)
        s.pop_back();

    int n = s.size();

    dp[0][0] = 1;
    dp[2][0] = 1; 
    dp[3][1] = 1; 

    for (int i = 1; i < n; i++) {
        for (int t = 0; t < 2; t++) {
            int len = t + 2;
            if (dp[i][t ^ 1] == 1 || (dp[i][t] && s.substr(i - len, len) != s.substr(i, len)))
                dp[i + len][t] = 1;
        }
    }
    //cout << s << endl;
    set < string > q;
    for (int i = 0; i < n; i++)
        if (dp[i][0] || dp[i][1]) {
            for (int len = 2; len <= 3; len++) {
                if (i + len <= n) {
                    string t = s.substr(i, len);
                    reverse(t.begin(), t.end());
                    q.insert(t);
                }
            }
        }
    printf("%d\n", (int)q.size());
    for (auto s: q) 
        cout << s << "\n";
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