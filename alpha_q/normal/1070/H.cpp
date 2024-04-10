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


struct simplehash{
    int len;
    long long base, mod;
    vector <int> P, H, R;

    simplehash(){}
    simplehash(const char* str, long long b, long long m){
        base = b, mod = m, len = strlen(str);
        P.resize(len + 3, 1), H.resize(len + 3, 0), R.resize(len + 3, 0);

        for (int i = 1; i <= len; i++) P[i] = (P[i - 1] * base) % mod;
        for (int i = 1; i <= len; i++) H[i] = (H[i - 1] * base + str[i - 1] + 1007) % mod;
        for (int i = len; i >= 1; i--) R[i] = (R[i + 1] * base + str[i - 1] + 1007) % mod;
    }

    inline int range_hash(int l, int r){
        int hashval = H[r + 1] - ((long long)P[r - l + 1] * H[l] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }

    inline int reverse_hash(int l, int r){;
        int hashval = R[l + 1] - ((long long)P[r - l + 1] * R[r + 2] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }
};

struct stringhash{
    simplehash sh1, sh2;
    stringhash(){}
    stringhash(const char* str){
        sh1 = simplehash(str, 1949313259, 2091573227);
        sh2 = simplehash(str, 1997293877, 2117566807);
    }

    inline long long range_hash(int l, int r){
        return ((long long)sh1.range_hash(l, r) << 32) ^ sh2.range_hash(l, r);
    }

    inline long long reverse_hash(int l, int r){
        return ((long long)sh1.reverse_hash(l, r) << 32) ^ sh2.reverse_hash(l, r);
    }
};

unordered_map < LL, int > hashFreq[10];
unordered_map < LL, string > hashExample[10];

inline void Insert(char *str) {
    int i, j, len = strlen(str);
    stringhash sh = stringhash(str);
    string here = str;
    rep(i, len) {
        for(j=i; j<len; j++) {
            LL now = sh.range_hash(i, j);
            if(hashExample[j-i+1].find(now) != hashExample[j-i+1].end() && hashExample[j-i+1][now] == here) continue;
            if(hashFreq[j-i+1].find(now) == hashFreq[j-i+1].end()) {
                hashFreq[j-i+1][now] = 1;
                hashExample[j-i+1][now] = here;
            }
            else {
                hashFreq[j-i+1][now]++;
                hashExample[j-i+1][now] = here;
            }
        }
    }
}

inline void Query(char *str) {
    int len = strlen(str);
    stringhash sh = stringhash(str);
    LL h = sh.range_hash(0, len-1);
    if(hashFreq[len].find(h) == hashFreq[len].end()) {
        puts("0 -");
        return;
    }
    printf("%d %s\n", hashFreq[len][h], hashExample[len][h].c_str());
}

int main() {
//    assert(freopen("in.txt","r",stdin));
//    assert(freopen("out.txt","w",stdout));

    int n;
    char str[12];

    sdi(n);
    while(n--) {
        sds(str);
        Insert(str);
    }
    sdi(n);
    while(n--) {
        sds(str);
        Query(str);
    }

    return 0;
}