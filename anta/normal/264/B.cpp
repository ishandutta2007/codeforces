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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define reps(i,n,s) for(int (i)=0;(i)<(int)(n);(i)+=(s))
#define reus(i,l,u,s) for(int (i)=(int)(l);(i)<(int)(u);(i)+=(s))
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

int n;

int a[111111];
int o[111111];
int facts[111111];

int dp[111111];
int rec(int i) {
    if(dp[i] != -1) return dp[i];
    int r = 1;
    if(a[i] != 1) {
        for(int j = 1, x =  (a[i]+a[i]-1)/a[i]*a[i]; x <= 100000; x += a[i], j ++) {
            if(i < o[x]) {
                r = max(r, 1 + rec(o[x]));
                break;
            }
        }
        int t = a[i];
        while(t > 1) {
            int y = facts[t];
            for(int j = 1, x = (a[i]+y-1)/y*y; x <= 100000; x += y, j ++) {
                if(i < o[x]) {
                    r = max(r, 1 + rec(o[x]));
                    break;
                }
            }
            t /= facts[t];
        }
    }
    return dp[i] = r;
}

int dp_naive[111111];
int rec_naive(int i) {
    if(dp_naive[i] != -1) return dp_naive[i];
    int r = 0;
    return dp_naive[i] = r;
}

int main() {
    mset(facts, 0);
    facts[0] = facts[1] = 1;
    for(ll i = 2; i <= 100000; i ++) if(facts[i] == 0) {
        facts[i] = i;
        for(ll j = i*i; j <= 100000; j += i) if(facts[j] == 0)
            facts[j] = i;
    }

    cin >> n;
//  n = 100000;
    mset(o, -1);
    rep(i, n) {
        cin >> a[i];
//      a[i] = i+1;
        o[a[i]] = i;
    }
    int r = 0;
    mset(dp, -1);
    rep(i, n) {
        r = max(r, rec(i));
    }
    cout << r << endl;
    return 0;
}