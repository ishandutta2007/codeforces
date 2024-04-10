#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

const int PRIMEFACTORIZES_MAXN = 10000000;
int primeFactor[PRIMEFACTORIZES_MAXN+1];
void primeFactorizes() {
    primeFactor[1] = 1;
    rer(i, 2, PRIMEFACTORIZES_MAXN) if(!primeFactor[i]) {
        primeFactor[i] = i;
        if((ll)i * i <= PRIMEFACTORIZES_MAXN)
        for(int j = i * i; j <= PRIMEFACTORIZES_MAXN; j += i) {
            if(!primeFactor[j]) primeFactor[j] = i;
        }
    }
}
ll deno[10000000+2];
const int PRIMES = 664579 + 10;
int primes[PRIMES];
ll denop[PRIMES];

int main() {
    primeFactorizes();
    int k;
    scanf("%d", &k);
    rep(i, k) {
        int a;
        scanf("%d", &a);
        deno[0] ++;
        deno[a+1] --;
    }
    //
    rer(i, 1, 10000000) deno[i] += deno[i-1];
    //
    for(int i = 10000000; i >= 2; i --) {
        ll d = deno[i];
        deno[i] = 0;
        deno[primeFactor[i]] += d;
        deno[i / primeFactor[i]] += d;
    }
    int primeCount = 0;
    rer(i, 2, 10000000) if(primeFactor[i] == i) {
        denop[primeCount] = deno[i];
        primes[primeCount++] = i;
    }
//  rer(i, 2, 10000000) if(deno[i] != 0)
//      cerr << i << "^" << deno[i] << " * ";
    ll l = 0, u = INFL;
    while(u-l > 1) {
        ll m = (l+u) / 2;
        bool ok = true;
        rep(i, primeCount) {
            int p = primes[i];
            ll x = 0, y = m / p;
            while(y) {
                x += y;
                if(denop[i] <= x) break;
                y /= p;
            }
            ok &= denop[i] <= x;
            if(!ok) break;
        }
        (ok ? u : l) = m;
    }
    cout << u << endl;
    return 0;
}