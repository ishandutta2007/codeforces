#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 1000000;
ll a[2*MAXN];
//ll b[1000000000]
vector<ll> out;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,k,x,y;
    scanf("%lld%lld", &n, &k);
    for(int i =0;i<2*n;i+=2){
        scanf("%lld%lld", &x, &y);
        a[i] = 2 * x;
        a[i + 1] = 2 * y + 1;
    }
    sort(a,a + 2 * n);
    ll v = 0;
    for(int i =0;i<2*n;i++){
        //cout << v << " " << k << endl;
        if(a[i] % 2 == 0){
            v++;
            if(v == k)out.push_back(a[i]);

        }else {
            if(v == k){
                out.push_back(a[i]-1);
            }
            v--;
        }
    }
    printf("%lld\n", ((ll) out.size())/2);
    for(int i =0;i<out.size()/2;i++)printf("%lld %lld\n",out[2*i]/2,out[2*i+1]/2);

    return 0;
}