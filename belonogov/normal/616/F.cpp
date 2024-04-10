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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int s[N];
int n;
int cost[N];
int cur;
int c[N];
int cn[N];
int p[N];
int pn[N];
int cnt[N];
int st[N];
int lcp[N];
int cc[N];
int where[N];
int ll[N];
int len[N];
int rev[N];
pair < int, int > stack[N];
long long pref[N];
int block[N];



void suf_mas() {
    int alf = 0;
    for (int i = 0; i < cur; i++) {
        cnt[s[i]]++; 
        alf = max(alf, s[i]);
    }
    st[0] = 0;
    for (int i = 0; i < alf; i++)
        st[i + 1] = st[i] + cnt[i]; 
    for (int i = 0; i < cur; i++)  {
        p[st[s[i]]++] = i;
        c[i] = s[i];
    }

    for (int step = 1; step < cur; step *= 2) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < cur; i++)
            cnt[c[i]]++;
        for (int i = 0; i < cur; i++) 
            pn[i] = (p[i] - step + cur) % cur;
        st[0] = 0;
        for (int i = 0; i < alf; i++)
            st[i + 1] = st[i] + cnt[i];

        for (int i = 0; i < cur; i++)
            p[st[c[pn[i]]]++] = pn[i];

        int nalf = 0; 

        cn[p[0]] = 0;
        for (int i = 1; i < cur; i++) {
            int c1 = c[p[i]];
            int c2 = c[(p[i] + step) % cur];
            int c3 = c[p[i - 1]];
            int c4 = c[(p[i - 1] + step) % cur];
            if (c1 != c3 || c2 != c4) {
                nalf++; 
            }
            cn[p[i]] = nalf;
        }
        nalf++;
        memcpy(c, cn, sizeof(cn));
        alf = nalf;
    }
}

vector < string > ss;

void read() {
    scanf("%d", &n);
    ss.resize(n);
    for (int i = 0; i < n; i++)
        cin >> ss[i];
    for (int i = 0; i < n; i++)
        scanf("%d", &cost[i]);
}


void calc_lcp() {
    for (int i = 0; i < cur; i++)
        rev[p[i]] = i; 
    int res = 0;  
    //cerr << "P  : ";
    //for (int i = 0; i < cur; i++)
        //cerr << p[i] << " ";
    //cerr << endl;

    //cerr << "rev: ";
    //for (int i = 0; i < cur; i++)
        //cerr << rev[i] << " ";
    //cerr << endl;
    for (int i = 0; i < cur; i++) {
        res = max(res - 1, 0);
        int pos = rev[i];
        if (pos + 1 == cur) {
            res = 0;
            continue;
        }
        int d = p[pos + 1];
        //db2(i, d);
        for (; d + res < cur && i + res < cur && s[d + res] == s[i + res]; res++);
        lcp[pos] = res;
    }
}

long long getSum(int l, int r) {
    return pref[r] - pref[l];
}

long long solve() {
    memset(s, 0, sizeof(s));
    memset(c , 0, sizeof(c));
    memset(cn, 0, sizeof(cn));
    memset(p , 0, sizeof(p));
    memset(pn, 0, sizeof(pn));
    memset(cnt, 0, sizeof(cnt));
    memset(st, 0, sizeof(st));
    memset(lcp, 0, sizeof(lcp));
    memset(cc, 0, sizeof(cc));
    memset(where, 0, sizeof(where));
    memset(ll, 0, sizeof(ll));
    memset(len, 0, sizeof(len));
    memset(rev, 0, sizeof(rev));
    memset(stack, 0, sizeof(stack));
    memset(pref, 0, sizeof(pref));
    memset(block, 0, sizeof(block));
    cur = 0;


    for (int i = 0; i < n; i++) {       
        len[i] = ss[i].size();
        where[i] = cur;
        for (int j = 0; j < len[i]; j++) {
            s[cur] = ss[i][j] - 'a';
            ll[cur] = len[i] - j;
            cur++;
        }
        s[cur++] = i + 30;
    }
    int cur2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len[i]; j++)
            cc[cur2++] = cost[i];
        cur2++;
    }
    assert(cur == cur2);

    suf_mas(); 
    calc_lcp();
    //for (int i = 0; i < cur; i++, puts("")) {
        //cerr << lcp[i] << ", " << cc[p[i]] << ": ";
        //for (int j = p[i]; j < cur; j++)
            //printf("%2d ", s[j]);
    //}
    //for (int i = 0; i < cur; i++)
        //cerr << cc[i] << " ";
    //cerr << endl;
    //for (int i = 0; i < cur; i++)
        //cerr << p[i] << " ";
    //cerr << endl;
    for (int i = 0; i < cur; i++)
        pref[i + 1] = pref[i] + cc[p[i]];
    for (int i = 1; i < n; i++)
        block[rev[where[i] - 1]] = 1;
    //for (int i = 0; i < cur; i++)
        //cerr << ll[i] << " ";
    //cerr << endl;

    int cur1 = 0;
    long long answer = 0;
    stack[cur1++] = mp(0, ll[p[0]]);
    for (int i = 1; i < cur; i++) {
        //cerr << "============== " << answer << endl;
        //db(i);
        //for (int j = 0; j < cur1; j++) {
            //cerr << "(" << stack[j].fr << ", " << stack[j].sc << ")  ";
        //}
        //cerr << endl;

        assert(cur1 > 0);
        int x = lcp[i - 1];
        if (stack[cur1 - 1].sc > x) {
            int pos = i;
            for (; cur1 > 0 && stack[cur1 - 1].sc > x; cur1--) {
                answer = max(answer, getSum(stack[cur1 - 1].fr, i) * stack[cur1 - 1].sc);
                pos = stack[cur1 - 1].fr;
            }
            for (; cur1 > 0 && stack[cur1 - 1].sc == x; cur1--)
                pos = stack[cur1 - 1].fr;
            if (lcp[i - 1] > 0)
                stack[cur1++] = mp(pos, lcp[i - 1]);
        }
        if (cur1 == 0 || stack[cur1 - 1].sc != ll[p[i]])
            stack[cur1++] = mp(i, ll[p[i]]);

        //for (; cur1 > 0 && stack[cur1 - 1].fr > lcp[i]; cur1--) {
            //int left = (cur - 1 == 0)? 0: stack[cur1 - 2].sc + 1;
            //answer = max(answer, getSum(left, i + 1) * stack[cur1 - 1].fr);
            //if (cur1 - 1 > 0) 
        //}

        //db(cur1);
        //if (cur1 == 0 || stack[cur1 - 1].fr < lcp[i]) {
            //stack[cur1] = mp(lcp[i], cc[p[i]] + cc[p[i + 1]]);
            //ff[cur1] = cc[p[i]];
            //cur1++;
        //}
        //else  {
            //db2("here", i);
            //assert(stack[cur1 - 1].fr == lcp[i]);
            //stack[cur1 - 1].sc += cc[p[i + 1]];
        //}
    }
    //for (int i = 0; i < n; i++) {
        //int g = rev[where[i]];
        //db(g);
        //db2(lcp[g], len[i]);
        //if (lcp[g] < len[i]) {
            //answer = max(answer, len[i] * 1ll * cost[i]);
        //}
    //}

    return answer;
}

void genTest() {
    int ALF = 2;
    n = 5;
    ss.clear();
    ss.resize(n);
    int T = 10;
    for (int i = 0; i < n; i++) {
        int len = rand() % T + 1;
        for (int j = 0; j < len; j++)
            ss[i] += 'a' + rand() % ALF;
    }
    for (int i = 0; i < n; i++)
        cost[i] = rand() % T - T / 2;
}

long long stupid() {
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < (int)ss[i].size(); l++) {
            for (int r = l + 1; r <= (int)ss[i].size(); r++) {
                string g = ss[i].substr(l, r - l);
                long long res = 0;
                int len = r - l;
                for (int j = 0; j < n; j++) {
                    for (int t = 0; t + len <= (int)ss[j].size(); t++)
                        if (ss[j].substr(t, len) == g)
                            res += cost[j];
                }
                res *= g.size();
                answer = max(answer, res);
            }
        }
    }
    return answer;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();        
        auto r1 = solve();
        auto r2 = stupid();
        if (r1 != r2) {
            db2(r1, r2);
            cerr << n << endl;
            for (int i = 0; i < n; i++)
                cerr << ss[i] << endl;
            for (int i = 0; i < n; i++)
                cerr << cost[i] << " ";
            cerr << endl;
        }
        assert(r1 == r2);
    }

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
            printf("%lld\n", solve());
            //printf("%lld\n", stupid());
        }
    }
    else {
        stress();
    } 
    return 0;
}