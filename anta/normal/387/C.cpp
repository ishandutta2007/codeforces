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

void z_algorithm(const char *s, int n, int z[]) {
    int L = 0, R = 0;
    for(int i = 1; i < n; i ++) {
        if(i > R) {
            L = R = i;
            while(R < n && s[R-L] == s[R]) R ++;
            z[i] = R-L; R --;
        }else {
            int k = i-L;
            if(z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while(R < n && s[R-L] == s[R]) R ++;
                z[i] = R-L; R --;
            }
        }
    }
}

bool lex_compare_to_init(const char *s, const int z[], int i, int x, int y) {
    if(x != y) return x < y;
    int t = z[i];
    if(t >= x) return false;
    return s[t] < s[i+t];
}

char p[100001];
int z[100001];
int main() {
    scanf("%s", p);
    int n = strlen(p);
    z_algorithm(p, n, z);
    int ans = 0, zeros = 0, prev = n;
    for(int i = n-1; i > 0; i --) {
        if(p[i] == '0') {
            zeros ++;
        }else {
            if(lex_compare_to_init(p, z, i, i, prev-i)) break;
            ans ++;
            zeros = 0; prev = i;
        }
    }
    ans ++;
    printf("%d\n", ans);
    return 0;
}