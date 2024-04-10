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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;
const int T = 1e5 + 1;
const int ALF = 26;

int m;
int curLen;
long long fact[N];
long long rFact[N];
char s[N];
long long g;
map < int, int > q;
vector < int > res[N];
int id;
int cur;

long long binPow(long long a, long long b) {
    long long res = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
    }
    return res;
}


void read() {
    scanf("%d", &m);
}

long long getC(long long n, long long k) {
    return fact[n] * rFact[k] % MOD * rFact[n - k] % MOD;
}

void changeLen() {
    if (q.count(curLen) == 0) {
        q[curLen] = cur;
        cur++;
    }
    id = q[cur];
}

struct Query {
    int n, k, id, answer;
    Query(int n, int k): n(n), k(k) { }
};

vector < Query > query;
long long deg[N];
long long degM[N];
long long pw26[N];
    
void solve() {
    deg[0] = 1;
    long long g = binPow(ALF, MOD - 2);
    degM[0] = 1;
    pw26[0] = 1;
    for (int i = 1; i <= T; i++) {
        deg[i] = deg[i - 1] * (ALF - 1) % MOD;
        pw26[i] = pw26[i - 1] * ALF % MOD;
        degM[i] = degM[i - 1] * g % MOD;
    }
    fact[0] = 1;
    for (int i = 1; i <= T; i++)
        fact[i] = fact[i - 1] * i % MOD;
    rFact[T] = binPow(fact[T], MOD - 2);
    for (int i = T - 1; i >= 0; i--)
        rFact[i] = rFact[i + 1] * (i + 1) % MOD;

    scanf("%s", s);
    curLen = strlen(s);
    for (int t = 0; t < m; t++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%s", s);
            curLen = strlen(s);
        }
        else {
            int n;
            scanf("%d", &n);
            query.pb(Query(n, curLen));
        }
    }
    for (int i = 0; i < (int)query.size(); i++)
        query[i].id = i;
    sort(query.begin(), query.end(), [](Query a, Query b) { return a.k < b.k || (a.k == b.k && a.n < b.n); }); 


    //db(degM[2] * pw26[2] % MOD);
    for (int i = 0; i < (int)query.size();) {
        int j = i;
        long long res = 0;
        int tmp = query[j].k - 1;
        for (; i < (int)query.size() && query[j].k == query[i].k; i++) {
            for (; tmp < (int)query[i].n;) {
                tmp++;
                //db2(query[j].n, query[j].k);
                res = (res + getC(tmp - 1, query[j].k - 1) * deg[tmp - query[j].k] % MOD * degM[tmp]) % MOD;
            }
            //db(tmp);
            //db(res);
            query[i].answer = res * pw26[query[i].n] % MOD;
        }

    }




    sort(query.begin(), query.end(), [](Query a, Query b)  { return a.id < b.id; });
    for (auto x: query)
        printf("%d\n", x.answer);
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