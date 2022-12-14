// https://arc091.contest.atcoder.jp/submissions/2961886

#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<cassert>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const ll N = 3e5 + 1e3;
ll ans[N],unq[N];
void inp(){
    ll n;scanf("%lld", &n);
    ll a=n, b=1;
    // a+b-1 <= n, n <= a*b
    for(ll i = 1; i <= n; i++) {
        ll j = (n + i - 1) / i;
        if(i + j - 1 <= n && n <= i * j) {
            if(a + b > i + j) {
                a = i;
                b = j;
            }
        }
    }
    if( a + b - 1 <= n && n <= a * b){
        ll cnt = n;
        for(ll i = b - 1;i>=0;i--){
            const ll begin = a * i + 1,
                  end = a * i + a;
            //printf("%d %d\n", begin , end );
            for(ll j = begin;j<=end && cnt >= i + 1 ;j++, cnt --){
                ans[ n - cnt ] = j;
            }
        }
        //assert( cnt == 0);
        memcpy( unq, ans, sizeof(ll) * n);
        sort(unq, unq + n);
        ll * ed = unique(unq, unq + n );
        sort( unq, ed);
        for(ll i =0 ;i<n;i++){
            if( i ){
                putchar(' ');
            }
            printf("%ld", lower_bound(unq, ed,  (ans[i])) - unq + 1);
        }
    }
    else printf("-1\n");
}
//e.cc by xsthunder at Mon Aug  6 10:28:04 2018