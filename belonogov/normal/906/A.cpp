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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = 1e5 + 10;
const int INF = 1.01e9;
typedef vector<int> vi;

char s[N];

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);   
    int S = 26;
    vector<int> can(S, 1);
    //int cand = S;
    int startCnt = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        char ch;
        scanf(" %c %s", &ch, s);
        if (startCnt && (ch == '?' || ch == '!')) {
            answer++;
        }
        if (ch == '?') {
            int id = s[0] - 'a';
            if (can[id]) {
                can[id] = 0;
            }
        }
        else {
            vector<int> has(S, 0);
            int len = strlen(s);
            for (int j = 0; j < len; j++) {
                has[s[j] - 'a'] = 1;
            }
            if (ch == '!') {
                for (int j = 0; j < S; j++) {
                    if (has[j] == 0) {
                        can[j] = 0;
                    }
                }
            }
            else {
                for (int j = 0; j < S; j++) {
                    if (has[j] == 1) {
                        can[j] = 0;
                    }
                }
            }
        }
        int realCnt = 0;
        for (auto x: can) {
            realCnt += x;
        }
        if (realCnt == 1) {
            startCnt = 1;
        }
    } 
    cout << max(0, answer - 1) << endl;

#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}