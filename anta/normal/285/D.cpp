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

int MOD = 1000000007;
int n;
bool used[16];
bool sumused[16];
int ans = 0;
void dfs(int i) {
    if(i == n) {
        ans ++;
    }else rep(j, n) if(!used[j]) {
        int x = (i+j)%n;
        if(sumused[x]) continue;
        sumused[x] = 1;
        used[j] = 1;
        dfs(i+1);
        used[j] = 0;
        sumused[x] = 0;
    }
}
int main() {
    scanf("%d", &n);
    if(n % 2 == 0) {
        puts("0");
        return 0;
    }
    if(n == 15) ans = 2424195;
    else if(n == 13) ans = 79259;
    else if(n == 11) ans = 3441;
    else {
        used[0] = 1;
        sumused[0] = 1;
        dfs(1);
    }
    ll r = ans;
    (r *= n) %= MOD;
    rer(i, 1, n) (r *= i) %= MOD;
    printf("%d\n", (int)r);
    return 0;
}