#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)

#define sz(x) (int) x.size()
#define pb push_back
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x))
#define un(x) x.erase(unique(all(x)), x.end())

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define OK cerr << "ok\n"
#define DB(x) cerr << #x << " = " << x << endl

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;

inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


struct data {
    bool subnetFlag;
    int black, white, nxt[2];

    void Clear() {
        subnetFlag = false;
        black = white = 0;
        mem(nxt, -1);
    }
} trie[6400005];

int freeNode;

inline void Insert(string str, int subnetPos, bool blackFlag) {
    int i, len = sz(str), cur=0;
    rep(i, len) {
        int x = str[i] - '0';
        if(trie[cur].nxt[x] == -1) {
            trie[freeNode].Clear();
            trie[cur].nxt[x] = freeNode++;
        }
        cur = trie[cur].nxt[x];
        if(i+1 == subnetPos) {
            if((blackFlag && trie[cur].white) || ((!blackFlag && trie[cur].black))) {
                puts("-1");
                exit(0);
            }
            trie[cur].black = blackFlag;
            trie[cur].white = !blackFlag;
            trie[cur].subnetFlag = true;
            return;
        }
    }
    if((blackFlag && trie[cur].white) || ((!blackFlag && trie[cur].black))) {
        puts("-1");
        exit(0);
    }
    trie[cur].black = blackFlag;
    trie[cur].white = !blackFlag;
}

inline string toBin(LL x) {
    string ret = "";
    while(x) {
        if(x&1ll) ret += "1";
        else ret += "0";
        x >>= 1ll;
    }
    int needed = 32-sz(ret);
    while(needed--) ret += "0";
    reverse(all(ret));
    return ret;
}

inline void Insert(char *str) {
    vector <LL> v;
    bool blackFlag = false;
    if(str[0] == '-') blackFlag = true;
    int i, len = strlen(str);
    for(i=1; i<len; i++) {
        if(!isalnum(str[i-1])) v.pb(atoll(&str[i]));
    }
    LL what = v[0]*(1ll<<24) + v[1]*(1ll<<16) + v[2]*(1ll<<8) + v[3];
    LL subnetPos = -1;
    if(sz(v) >= 5) subnetPos = v[4];
    Insert(toBin(what), subnetPos, blackFlag);
}

void dfs(int u) {
    bool isBlack = trie[u].black;
    for(int i=0; i<=1; i++) {
        int v = trie[u].nxt[i];
        if(v != -1) {
            dfs(v);
            trie[u].black += trie[v].black;
            trie[u].white += trie[v].white;
        }
    }
    if(trie[u].subnetFlag && isBlack && trie[u].white) {
        puts("-1");
        exit(0);
    }
    if(trie[u].subnetFlag && !isBlack && trie[u].black) {
        puts("-1");
        exit(0);
    }
}

vector <string> ipList;

void fuck(int u, string ip = "") {
    if(trie[u].black && !trie[u].white) {
        ipList.pb(ip);
        return;
    }
    for(int i=0; i<=1; i++) {
        int v = trie[u].nxt[i];
        if(v != -1) {
            ip += i +'0';
            fuck(v, ip);
            ip.pop_back();
        }
    }
}

inline int toInt(string s) {
    int ret = 0, what = 1;
    reverse(all(s));
    for(auto x:s) {
        if(x == '1') ret += what;
        what <<= 1;
    }
    return ret;
}

inline void printIP(string s) {
    int subnet = sz(s);
    if(subnet < 32) { /// zero padding
        int needed = 32-subnet;
        while(needed--) s += "0";
    }
    string now = "";
    int cnt = 0;
    for(auto x:s) {
        now += x;
        if(sz(now) == 8) {
            printf("%d", toInt(now));
            if(cnt <= 2) {
                printf(".");
                now = "";
            }
            cnt++;
        }
    }
    printf("/%d\n", subnet);
}

int main() {
//    assert(freopen("in.txt","r",stdin));
//    assert(freopen("out.txt","w",stdout));

//    double x = sizeof(trie) / 1024.0 / 1024.0;
//    DB(x);

    char str[35];
    int n;

    trie[0].Clear();
    freeNode = 1;
    sdi(n);
    while(n--) {
        sds(str);
        Insert(str);
    }
    dfs(0);
    fuck(0);
    pfi(sz(ipList));
    for(auto x:ipList) printIP(x);

    return 0;
}