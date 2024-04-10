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
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;

string s;
char res[2][100];

void read() {
    cin >> s;
    int n = s.size();
    map<char,int> q;
    int p1 = -1, p2 = -1;
    for (int i = 0; i < (int)s.size(); i++) {
        if (q.count(s[i]) == 0) {
            q[s[i]] = i;
        }
        else {
            p1 = q[s[i]];
            p2 = i;
        }
    }
    if (p2 - p1 == 1) {
        puts("Impossible");
        return;
    }
    int m = 13;
    int mid = (p1 + p2 - 1) / 2;
    int cur = mid;
    for (int i = 0; i < m; i++) {
        res[0][i] = s[(cur + n) % n];
        cur--;
    } 
    cur = mid + 1;
    //db3(p1, p2, s[p1]);
    for (int i = 0; i < m; i++) {
        if (cur == p2) {
            cur++;
        } 
        res[1][i] = s[(cur + n) % n];
        cur++;
    }


    //cerr << s << endl;
    printf("%s\n%s\n", res[0], res[1]);

}

void solve() {

}

void stress() {

}

int main(){
#ifdef MY_DEBUG
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