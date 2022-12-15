#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int os[100001];
lli ps[100101];
int n,q;
const lli mod=1e9+7;

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%1d",os+i),os[i]+=os[i-1];
    ps[1]=1;
    for(int i=2;i<=100001;i++) ps[i]=ps[i-1]*2%mod;
    for(int i=2;i<=100001;i++) ps[i]=(ps[i]+ps[i-1])%mod;

    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int a=os[r]-os[l-1],b=(r-l+1)-a;
        printf("%lld\n",(ps[a+b]-ps[b]+mod)%mod);
    }

    return 0;
}