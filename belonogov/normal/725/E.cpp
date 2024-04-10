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
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;


int c;
int n;
int a[N];
vector<pair<int,int>> b;

void read() {
    scanf("%d%d", &c, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int go(int curC, int cur) {
    for (; curC > 0; ) {
        int pos = lower_bound(b.begin(), b.begin() + cur, mp(curC, (int)INF)) - b.begin() - 1;
        if (pos == -1) break;
        int cnt = curC / b[pos].fr;
        int x = min(cnt, b[pos].sc);
        curC -= x * b[pos].fr;
        cur = pos;
    }
    return curC == 0;
}


int solve() {
    sort(a, a + n); 
    b.clear();
    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && a[i] == a[j]; i++);
        b.pb(mp(a[j], i - j));
    }
    int answer = INF;
    int curC = c;
    int prev = c;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= curC) {
            for (int cand = prev - 1; cand >= a[i]; cand--) {
                int id = lower_bound(all(b), mp(a[i], -1)) - b.begin();

                if (curC > cand && !go(curC - cand, id + 1))
                    answer = cand;
            } 
            curC -= a[i];
        }
        prev = a[i];
    }

    if (answer == INF)
        answer = -1;
    return answer;
}

void printAns(int answer) {
    if (answer == -1)
        puts("Greed is good");
    else {
        cout << answer << endl;
    }
}

void genTest() {
    n = 10;
    int T = 20;
    c = T * 3;
    for (int i = 0; i < n; i++) {
        a[i] = rand() % T + 1;
    }
    sort(a, a + n);
    int curC = c; 
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= curC)
            curC -= a[i];
    }
    c -= curC;
}

int stupid() {
    for (int i = 1; i < c; i++) {
        vector<int> h;
        for (int j = 0; j < n; j++)
            h.pb(a[j]);
        h.pb(i);
        sort(all(h));
        int curC = c;
        for (int j = h.size() - 1; j >= 0; j--)
            if (h[j] <= curC)
                curC -= h[j];
        if (curC != 0)
            return i;
    }
    return -1;
}

void printTest() {
    cout << c << endl << n << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        auto r1 = solve();
        auto r2 = stupid();
        //db2(r1, r2);
        if (r1 != r2) {
            db2(r1, r2);
            printTest();

            assert(false);
        }
    }

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
            printAns(solve());
            //printAns(stupid());
        }
    }
    else {
        stress();
    }

    return 0;
}