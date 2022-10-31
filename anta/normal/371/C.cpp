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

int main() {
    string s;
    cin >> s;
    int n[3] = {};
    cin >> n[0] >> n[1] >> n[2];
    int p[3] = {};
    cin >> p[0] >> p[1] >> p[2];
    ll r;
    cin >> r;
    int len = s.size();
    int x[3] = {};
    rep(i, len) {
        char c = s[i];
        if(c == 'B') x[0] ++;
        if(c == 'S') x[1] ++;
        if(c == 'C') x[2] ++;
    }
    ll l = 0, u = (ll)1e13;
    while(u-l > 0) {
        ll mid = (l+u+1) / 2;
        ll req = 0;
        rep(i, 3)
            req += max(0LL, x[i] * mid - n[i]) * p[i];
        if(req <= r) l = mid;
        else u = mid-1;
    }
    cout << l << endl;
    return 0;
}