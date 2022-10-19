#include <iostream>
#include <vector>

#define M 100100
#define long long long
#define INF 1000000000000000ll

using namespace std;

long n,w[M],l,r,ql,qr,sp[M],sum=0;
long ans=INF;

long lol(long a, long b, long l, long r){
    if (a>b)
        swap(a,b),swap(l,r);

    long t=b-a-1,ans=0;
    if (t>=0)
        ans=t*r;

    return ans;
}

void read(void){
    cin>>n>>l>>r>>ql>>qr;
    for (int i=1; i<=n; ++i)
        cin>>w[i],sp[i]=sp[i-1]+w[i],sum+=w[i];

    ans=min(ans,sum*r+(n-1)*qr);
    ans=min(ans,sum*l+(n-1)*ql);

    for (int i=1; i<n; ++i){
        long a=i,b=n-i;
        ans=min(ans,l*sp[i]+r*(sum-sp[i])+lol(a,b,ql,qr));
    }

    cout<<ans<<"\n";


}

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("text.in","r",stdin);
    //freopen("text.out","w",stdout);
    read();
    return 0;
}