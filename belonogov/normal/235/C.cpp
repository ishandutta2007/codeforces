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
const int N = 2e6 + 10;
const long long INF = 1e9 + 19;
const int ALF = 26;

struct Node {
    int next[ALF];
    int link;
    int len;
    int cnt;
    Node() {
        memset(next, -1, sizeof(next));
        link = -1;
        len = 0;
        cnt = 0;
    }
    void Epr() {
        cerr << "next: ";
        for (int i = 0; i < 4; i++)
            cerr << next[i] << " ";
        cerr << "   link len cnt: " << link << " " << len << " " << cnt << endl;
    }
};

char s[N];
char t[N];
Node st[N];
int sz;
int last;


void read() {
    scanf("%s", s);
}

void addLetter(char ch) {
    int c = ch - 'a'; 
    //db(c);
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].cnt = 1;
    int p;
    for (p = last; p != -1 && st[p].next[c] == -1; p = st[p].link)
        st[p].next[c] = cur;
    //db(p);
    if (p == -1)  
        st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            for (int k = 0; k < ALF; k++)
                st[clone].next[k] = st[q].next[k];
            st[clone].link = st[q].link;
            for (; p != -1 && st[p].next[c] == q;  p = st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int z[N];

void z_f() {
    int len = strlen(t);
    int l = 0, r = 0;
    for (int i = 1; i < len; i++) {
        z[i] = 0;
        if (r > i) 
            z[i] = min(z[i - l], r - i);
        for (; i + z[i] < len && t[z[i]] == t[z[i] + i]; z[i]++);
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
}

vector < int > e[N];

void dfs(int v) {
    for (auto u: e[v]) {
        dfs(u);
        st[v].cnt += st[u].cnt;
    }
}

void solve() {
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    int m = strlen(s);
    for (int i = 0; i < m; i++) 
        addLetter(s[i]);


    //cerr << endl;

    for (int i = 1; i < sz; i++) {
        e[st[i].link].pb(i);
    }
    dfs(0);
    //for (int i = 0; i < sz; i++)
        //st[i].Epr();

    int q;
    scanf("%d", &q);
    //db(q);
    for (int i = 0; i < q; i++) {
        scanf("%s", t);
        z_f();
        int n = strlen(t);
        int per = n;
        for (int i = 1; i < n; i++) {
            if (n % i == 0 && i + z[i] == n) {
                per = i;
                break;
            }
        } 
        //for (int i = 0; i < n; i++)
            //cerr << z[i] << " ";
        //cerr << endl;

        for (int j = 0; j < n; j++)
            t[j + n] = t[j];
        int cur = 0;
        int v = 0;
        int answer = 0;
        //db(per);
        for (int j = 0; j < per;) {
            if (cur < j) {
                cur = j;
                v = 0;
            }
            //cerr << "j cur v: " << j << " " << cur << " " << v << endl;
            for (; cur - j < n; ) {
                int ch = t[cur] - 'a';
                if (st[v].next[ch] != -1) {
                    v = st[v].next[ch];
                    cur++;
                }
                else
                    break;
            } 
            if (cur - j == n) {
                answer += st[v].cnt;
            }
            j++;
            if (j <= cur) {
                int pLen = (st[v].link == -1)? 0: st[st[v].link].len;
                assert(cur - j >= pLen);
                if (cur - j == pLen)
                    v = st[v].link;
            }
        }
        printf("%d\n", answer);
    }

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