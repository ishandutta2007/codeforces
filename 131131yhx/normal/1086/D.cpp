#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#define PI pair <int, int>
#define SIT set <int>::iterator
#define f first
#define s second

#define M 400010

using namespace std;

int n, q, X[M], S[3][M];

char ch[M];

set <int> mmp[3];

int getv(char x) {
    if(x == 'S') return 0;
    else if(x == 'R') return 1;
    else if(x == 'P') return 2;
    return -1;
}

void add(int w, int x, int v) {
    for(int i = x; i <= n; i += i & -i) S[w][i] += v;
}

int ask(int w, int x) {
    int ans = 0;
    for(int i = x; i; i -= i & -i) ans += S[w][i];
    return ans;
}

int getmn(int x) {
    if(mmp[x].empty()) return n + 1;
    return *mmp[x].begin();
}

int getmx(int x) {
    if(mmp[x].empty()) return 0;
    SIT it = mmp[x].end();
    it--;
    return *it;
}

int Do() {
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        int l_1 = getmn((i + 2) % 3), l_2 = getmn((i + 1) % 3);
        int r_1 = getmx((i + 2) % 3), r_2 = getmx((i + 1) % 3);
        l_2 = min(l_2, l_1);
        r_2 = max(r_2, r_1);
        if(l_1 <= r_1) {
            ans += ask(i, l_2);
            ans += ask(i, r_1) - ask(i, l_1 - 1);
            ans += ask(i, n) - ask(i, r_2 - 1);
        } else if(l_2 <= r_2) {
            
        } else {
            ans += ask(i, n);
        }
    }
    return ans;
}

void prprpr() {
    for(int i = 1; i <= n; i++) {
        add(X[i], i, 1);
        mmp[X[i]].insert(i);
    }
}

void change(int x, int v) {
    mmp[X[x]].erase(x);
    add(X[x], x, -1);
    X[x] = v;
    mmp[X[x]].insert(x);
    add(X[x], x, 1);
}

int main() {
    scanf("%d%d", &n, &q);
    scanf("%s", ch + 1);
    for(int i = 1; i <= n; i++) X[i] = getv(ch[i]);
    prprpr();
    printf("%d\n", Do());
    while(q--) {
        int x;
        char ch[5];
        scanf("%d%s", &x, ch);
        change(x, getv(ch[0]));
        printf("%d\n", Do());
    }
    return 0;
}