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
const int N = 1e5 + 10;
const int INF = 1e9 + 19;

struct SMIN {
    vector < pair < int, int > > data;
    void add(int x) {
        if (data.empty())
            data.pb(mp(x, x));
        else
            data.pb(mp(min(data.back().fr, x), x));
    }
    int pop() {
        assert(!data.empty());
        int r = data.back().sc;
        data.pop_back();
        return r;
    }
    int get() {
        if (data.empty())
            return INF;
        return data.back().fr;
    }
    bool empty() {
        return data.empty();
    }
    int size() {
        return data.size();
    }
};

struct QMIN {
    SMIN s1, s2;
    void add(int x) {
        s1.add(x);
    }
    int get() {
        return min(s1.get(), s2.get());
    }
    void pop() {
        if (s2.empty()) {
            for (; !s1.empty(); ) 
                s2.add(s1.pop());
        }
        s2.pop();
    }
    int size() {
        return s1.size() + s2.size();
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }
};


int n, s, l;
int a[N];
int dp[N];

void read() {
    scanf("%d%d%d", &n, &s, &l);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    //SMIN m;
    //m.add(1);
    //db(m.get());
    //m.add(2);
    //db(m.get());
    //m.pop();
    //db(m.get());
    //return;

    
    memset(dp, 63, sizeof(dp));
    dp[0] = 0;
    QMIN mn, mx; 
    QMIN mnDp;
    for (int i = 0; i < n; i++) {
        mn.add(a[i]);
        mx.add(-a[i]);
        //db2(-mx.get(), mn.get());
        for (;-mx.get() - mn.get() > s;) {
            mx.pop();
            mn.pop();
        }
        //db2(-mx.get(), mn.get());
        //db(mn.size());
        if (i + 1 >= l) {
            mnDp.add(dp[i + 1 - l]);  
        } 
        for (;!mnDp.empty() && mnDp.size() + l - 1 > mn.size(); mnDp.pop());
        if (!mnDp.empty())
            dp[i + 1] = mnDp.get() + 1;

    }
    //for (int i = 0; i <= n; i++)
        //cerr << dp[i] << " ";
    //cerr << endl;
    if (dp[n] > INF) 
        puts("-1");
    else
        printf("%d\n", dp[n]);
    
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