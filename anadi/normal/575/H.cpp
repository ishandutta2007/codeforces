#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const LL mx=1e9+7LL;
const int mxn=2*(1e6+7);

LL silnie[mxn], silnia[mxn];

LL szybkie(LL a, LL b){
    if(b==0)
        return 1LL;
    LL x=szybkie(a, b/2LL);
    if(b%2==0LL)
        return (x*x)%mx;
    return (((x*x)%mx)*a)%mx;
}

LL RevMod(LL a){
    a=szybkie(a, mx-2LL);
    return a;
}

int main(){

    LL n;
    cin >> n;
    
    LL result=(szybkie(2LL, 2LL*n+1LL) - 1LL)%mx;

    silnie[0]=1LL;
    for(int i=1; i<=2*n; ++i)
        silnie[i]=(silnie[i-1]*(LL)i)%mx;
    
    silnia[0]=1LL;
    for(int i=1; i<=n; ++i)
        silnia[i]=(((silnia[i-1]*(n+(LL)i))%mx)*RevMod(i))%mx;
    
    for(int i=0; i<=n; ++i){
        LL k= n-(LL)i;
        result-=((szybkie(2LL, k)-1)*2LL*silnia[i])%mx;
        result%=mx;
    }
    result+=mx;
    result%=mx;
    
    cout << result;
    
    return 0;
}