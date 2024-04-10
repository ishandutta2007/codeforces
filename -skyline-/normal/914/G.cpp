//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
ll n,a[131111],f[131111],b[18][131111],cnt[131111],c[18][131111],x[131111],y[131111],z[131111],ans;
void fwt_or(ll *a){
    for(ll i=2;i<=n;i<<=1){
        for(ll j=0;j<n;j+=i){
            for(ll k=0;k<(i>>1);++k){
                ll l=j+k,r=l+(i>>1);
                a[r]+=a[l];
                if(a[r]>=orz)a[r]-=orz;
            }
        }
    }
}
void ifwt_or(ll *a){
    for(ll i=2;i<=n;i<<=1){
        for(ll j=0;j<n;j+=i){
            for(ll k=0;k<(i>>1);++k){
                ll l=j+k,r=l+(i>>1);
                a[r]+=orz-a[l];
                if(a[r]>=orz)a[r]-=orz;
            }
        }
    }
}
void fwt_and(ll *a){
    for(ll i=2;i<=n;i<<=1){
        for(ll j=0;j<n;j+=i){
            for(ll k=0;k<(i>>1);++k){
                ll l=j+k,r=l+(i>>1);
                a[l]+=a[r];
                if(a[l]>=orz)a[l]-=orz;
            }
        }
    }
}
void ifwt_and(ll *a){
    for(ll i=2;i<=n;i<<=1){
        for(ll j=0;j<n;j+=i){
            for(ll k=0;k<(i>>1);++k){
                ll l=j+k,r=l+(i>>1);
                a[l]+=orz-a[r];
                if(a[l]>=orz)a[l]-=orz;
            }
        }
    }
}
void fwt_xor(ll *a){
    for(ll i=2;i<=n;i<<=1){
        for(ll j=0;j<n;j+=i){
            for(ll k=0;k<(i>>1);++k){
                ll l=j+k,r=l+(i>>1),x=a[l]+a[r],y=a[l]+orz-a[r];
                a[l]=x,a[r]=y;
                if(a[l]>=orz)a[l]-=orz;
                if(a[r]>=orz)a[r]-=orz;
            }
        }
    }
}
void ifwt_xor(ll *a){
    for(ll i=2;i<=n;i<<=1){
        for(ll j=0;j<n;j+=i){
            for(ll k=0;k<(i>>1);++k){
                ll l=j+k,r=l+(i>>1),x=a[l]+a[r],y=a[l]+orz-a[r];
                a[l]=x,a[r]=y;
                if(a[l]>=orz)a[l]-=orz;
                if(a[r]>=orz)a[r]-=orz;
                if(a[l]&1)a[l]+=orz;
                if(a[r]&1)a[r]+=orz;
                a[l]>>=1,a[r]>>=1;
            }
        }
    }
}
int main(){
    f[1]=1;
    for(ll i=2;i<131072;++i){
        f[i]=f[i-1]+f[i-2];
        if(f[i]>=orz)f[i]-=orz;
    }
    for(ll i=1;i<131072;++i)cnt[i]=cnt[i&(i-1)]+1;
    scanf("%I64d",&n);
    for(ll i=1;i<=n;++i){
        ll x;
        scanf("%I64d",&x);
        ++a[x],++b[cnt[x]][x];
    }
    n=131072;
    for(ll i=0;i<=17;++i)fwt_or(b[i]);
    for(ll i=0;i<=17;++i){
        for(ll j=0;i+j<=17;++j){
            for(ll k=0;k<131072;++k)c[i+j][k]=(c[i+j][k]+b[i][k]*1ll*b[j][k])%orz;
        }
    }
    for(ll i=0;i<=17;++i)ifwt_or(c[i]);
    for(ll i=0;i<131072;++i)x[i]=c[cnt[i]][i]*f[i]%orz,y[i]=a[i],z[i]=f[i]*1ll*a[i]%orz;
    fwt_xor(y);
    for(ll i=0;i<131072;++i)y[i]=y[i]*1ll*y[i]%orz;
    ifwt_xor(y);
    for(ll i=0;i<131072;++i)y[i]=y[i]*1ll*f[i]%orz;
    fwt_and(x),fwt_and(y),fwt_and(z);
    for(ll i=0;i<131072;++i)x[i]=x[i]*1ll*y[i]%orz*z[i]%orz;
    ifwt_and(x);
    for(ll i=1;i<131072;i<<=1){
        ans+=x[i];
        if(ans>=orz)ans-=orz;
    }
    printf("%I64d\n",ans);
    //system("pause");
    return 0;
}