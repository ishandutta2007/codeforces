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
const int N = 555;
const long long INF = 1e9 + 19;

char s[N];
int k, n;

void read() {
    scanf("%s", s);
    scanf("%d", &k);
    n = strlen(s);
    for (int i = 0; i < k; i++)
        s[i + n] = '*';
    n += k;
}

void solve() {
    int answer = 0;
    //db(s);
    //db(n);
    for (int l = 0; l < n; l++) {
        for (int len = 2; l + len <= n; len += 2) {
            //db2(l, len);
            int half = len / 2;
            bool flag = 1;
            for (int i = 0; flag && i < half; i++) {
                if (s[l + i] == '*' || s[l + i + half] == '*') continue;
                flag &= s[l + i] == s[l + i + half]; 
            }
            if (flag)
                answer = max(answer, len);
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