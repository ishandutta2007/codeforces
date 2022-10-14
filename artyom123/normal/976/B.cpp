#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
ll n,m,k;
ll x,y;
/*==================Define Area================*/
int main() {
    read(n);read(m);read(k);
    if(k<n) {
        x=k+1,y=1;
        printf("%lld %lld\n",x,y);
        return 0;
    }
    if(k==n) {
        x=n,y=2;
        printf("%lld %lld\n",x,y);
        return 0;
    }
    k=k-n;
    ll minus=m-1;
    minus*=2;
    // printf("%lld %lld\n",minus,k);
    ll ans=k/minus;
    ll ret=k%minus;
    // printf("%lld %lld\n",ans,ret);
    x=n-ans*2;
    minus/=2;
    if(ret<=minus-1) {
        y=2+ret;
    }
    else {
        x--;
        ret=ret-minus+1;
        y=m-ret+1;
    }
    printf("%lld %lld\n",x,y);
    return 0;
}