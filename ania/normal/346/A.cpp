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

int a[111];

int main() {
    int n, g = 0, mx = 0;
    scanf("%d", &n);
    FOR(i,n) {
        scanf("%d", &a[i]);
        if (i == 0) {
            g = a[i];
        } else {
            g = __gcd(a[i], g);
        }
        mx = max(a[i], mx);
    }
    int cnt = mx / g;
    printf("%s\n", (cnt + n) % 2 ? "Alice" : "Bob");
    return 0;
}