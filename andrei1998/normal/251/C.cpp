#include <iostream>
#include <algorithm>
#include <cstring>

#define lint long long int
#define inf 500000005
#define mod 360360
using namespace std;

int k;
int din[mod+5];

inline int calc (int a, int b) {
    memset(din,0,sizeof(din));

    for(int i=0;i<a;i++)
        din[i]=inf;

    int j;
    for(int i=a+1;i<=b;i++) {
        din[i]=din[i-1]+1;
        for(j=2;j<=k;j++)
            if((i%j)>0)
                din[i]=min(din[i],1+din[i-(i%j)]);
    }

    return din[b];
}

int main()
{
    lint a=1,b=1;
    cin>>b>>a>>k;

    lint c=b/mod-a/mod;

    if(!c) {
        cout<<calc(a%mod,b%mod)<<'\n';
        return 0;
    }

    cout<<c+(c-1)*calc(0,mod-1)+calc(a%mod,mod-1)+calc(0,b%mod)<<'\n';
    return 0;
}