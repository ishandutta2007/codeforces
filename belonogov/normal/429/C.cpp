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
const int N = 26;
const long long INF = 1e9 + 19;

int n;
int cnt[N];
int st[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
}

void ret(int flag) {
    if (flag) 
        puts("YES");
    else
        puts("NO");
    exit(0);
}

void rec(int pos, int cur);

void rec2(int pos, int cur, int curCnt, int sum, int c) {
    //cerr << "pos cur curCnt sum: " << pos << " " << cur << " " << curCnt << " " << sum << endl;
    if (sum > st[pos]) return;
    if (sum == st[pos]) {
        assert(c >= 1);
        if (c == 1) return;
        rec(pos + 1, cur);      
        return;
    }
    for (; curCnt > 0 && cnt[curCnt] == 0; curCnt--);
    if (curCnt == 0) return;
    rec2(pos, cur, curCnt - 1, sum, c);
    cnt[curCnt]--;
    if (curCnt > 1) {
        st[cur] = curCnt - 1;
        rec2(pos, cur + 1, curCnt, sum + curCnt, c + 1);
    }
    else {
        rec2(pos, cur, curCnt, sum + curCnt,  c + 1);
    }
    cnt[curCnt]++;
}

void rec(int pos, int cur) {
    //db2(pos, cur);
    if (pos == cur) {
        bool flag = 1;
        for (int i = 0; i <= n; i++)
            flag &= cnt[i] == 0;
        assert(flag);
        ret(1);
    }
    rec2(pos, cur, n, 0, 0);        
}

void solve() {
    if (cnt[n] != 1) ret(0);
    st[0] = n - 1;
    cnt[n]--;
    if (n == 1) ret(1);
    rec(0, 1);
    ret(0);
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