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
#if defined(_MSC_VER) || __cplusplus > 199711L
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

const int GETPRIMEFACTORS_MAXN = 10000000;
int primeFactors[GETPRIMEFACTORS_MAXN+1];
void getPrimeFactors() {
    primeFactors[1] = 1;
    rer(i, 2, GETPRIMEFACTORS_MAXN) if(!primeFactors[i]) {
        primeFactors[i] = i;
        if((ll)i * i <= GETPRIMEFACTORS_MAXN)
        for(int j = i * i; j <= GETPRIMEFACTORS_MAXN; j += i) {
            if(!primeFactors[j]) primeFactors[j] = i;
        }
    }
}

int cnt[10000000+1];
int main() {
    getPrimeFactors();
    int n;
    scanf("%d", &n);
    rep(i, n) {
        int x;
        scanf("%d", &x);
        while(x != 1) {
            int p = primeFactors[x];
            cnt[p] ++;
            do { x /= p; }while(x % p == 0);
        }
    }
    rer(i, 1, 10000000) cnt[i] += cnt[i-1];
    int m;
    scanf("%d", &m);
    rep(i, m) {
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = cnt[min(r, 10000000)] - cnt[min(10000000, max(l-1, 0))];
        printf("%d\n", ans);
    }
    return 0;
}