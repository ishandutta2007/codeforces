#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = 2000;
const int inf = (int)1e9;
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 9;
const long long p1 = 97;
const long long p2 = 997;

long long hash1[maxn];
long long hash2[maxn];
long long st1[maxn];
long long st2[maxn];

char s[maxn];
char s1[maxn];
int sum[maxn];

set < pair < long long, long long > > q;

long long gethash(int l, int r, long long * hash, long long * st, long long mod){
    return (hash[r] - (hash[l] * st[r - l]) % mod + mod) % mod;
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int ans = 0, n, r, k, d;
    long long hs1, hs2;
    scanf("%s", s);
    scanf("%s", s1);
    scanf("%d", &k);

    n = strlen(s);
    for(int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + ((s1[s[i] - 'a'] - '0') ^ 1);
    
    hash1[0] = hash2[0] = 1;
    for(int i = 0; i < n; i++){
        hash1[i + 1] = (hash1[i] * p1 + s[i]) % mod1;
        hash2[i + 1] = (hash2[i] * p2 + s[i]) % mod2;
    }
    st1[0] = st2[0] = 1;
    for(int i = 0; i <= n; i++){
        st1[i + 1] = (st1[i] * p1) % mod1;
        st2[i + 1] = (st2[i] * p2) % mod2;
    }
    /*
    for(int i = 0; i < n + 1; i++)
        epr("%d ", sum[i]);
    epr("\n");*/
    
    
    for(int len = 1; len <= n; len++){
        q.clear();
        for(int l = 0; l + len <= n; l++){
            r = l + len;
            d = sum[r] - sum[l];
            if (d <= k){
    hs1 = gethash(l, r, hash1, st1, mod1);
    hs2 = gethash(l, r, hash2, st2, mod2);  
//  cerr << "hs1 " << hs1 << "  hs2 " << hs2 << endl;
    q.insert(mp(hs1, hs2));
            }            
        }
//         epr("len %d  %d\n", len, (int)q.size());
        ans += q.size();        
    }
    cout << ans << endl;

    return 0;
}