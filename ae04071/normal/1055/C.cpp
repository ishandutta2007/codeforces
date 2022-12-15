#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<lli,int> pli;
typedef pair<int,int> pii;

int main(){
    lli la,ra,ta,lb,rb,tb;
    scanf("%lld%lld%lld%lld%lld%lld",&la,&ra,&ta,&lb,&rb,&tb);
    if(la>lb){
        swap(la,lb); swap(ra,rb); swap(ta,tb);
    }

    lli g=__gcd(ta,tb),s=max(la-lb,lb-la)%g;
    lli k=(lb-la)/g;
    printf("%lld\n",max(max(min(k*g+ra,rb)-max(k*g+la,lb)+1, min((k+1)*g+ra,rb)-max((k+1)*g+la,lb)+1),0ll));

    return 0;
}