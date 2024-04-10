#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int x[100100];
int nx[100100];
int rm[100100];

int main() {
    int n;
    scanf("%d", &n);
    FOR(i,n) scanf("%d", &x[i]);
    sort(x,x+n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (m == 0 || x[i] != x[m-1]) {
            x[m] = x[i];
            m++;
        }
    }
    int a,b,res=0;
    scanf("%d%d", &a, &b);
    while (a != b) {
        int best = a-1;
        for (int i = 0; i < m; i++) {
            int next = a - a%x[i];
            if (next >= b) {
                best = min(best, next);
            } else {
                rm[i] = true;
            }
        }
        int mn = 0;
        for (int i = 0; i < m; i++) {
            if (!rm[i]) {
                nx[mn] = x[i];
                mn++;
            }
        }
        for (int i = 0; i < mn; i++) {
            x[i] = nx[i];
            rm[i] = false;
        }
        m = mn;
        a = best;
        res++;
    }
    printf("%d\n", res);
    return 0;
}