#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

pii t[100100];

int main() {
    int n, res = 0;
    scanf("%d", &n);
    FOR(i,n) {
        scanf("%d%d", &t[i].fi, &t[i].se);
    }
    FOR(i,n) {
        int left = t[i].se;
        int dk = 1;
        while (left > (1LL<<(2*dk))) {
            dk++;
        }
        res = max(res, t[i].fi + dk);
    }
    printf("%d\n", res);
	return 0;
}