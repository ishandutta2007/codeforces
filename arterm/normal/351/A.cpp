#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define M 2011
#define long long long

using namespace std;

long a[2*M],n,s=0;
double b[2*M];

int mod(int x){
    return x<0 ? -x:x;
}

long fix(long x){
    int r=x%100;
    if (r>80)
        return x+100-r;
    return x-r;
}

void read(void){
    cin>>n;
    int z=0;
    for (int i=0; i<2*n; ++i){
        cin>>b[i];
        a[i]=100000*b[i];
        a[i]=fix(a[i])/100;
        a[i]%=1000;
        s+=a[i];
        if (a[i]!=0)
            z++;
    }
    int ans=1000000000;
    for (int i=0; i<=n; ++i)
        if (i<=z && n-i<=2*n-z)
            ans=min(ans,mod(1000*i-s));
    cout.precision(3);
    cout<<fixed<<ans/1000.0<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    read();

    return 0;
}