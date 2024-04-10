#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define mod 1000000007
using namespace std;

bool lucky(int x)
{
    if(!x)
        return 1;

    if(x%10!=4 && x%10!=7)
        return 0;
    return lucky(x/10);
}

vector<int> normal;
vector<int> special;

int fact[100005];
int invfact[100005];

int exp(int a,int b)
{
    if(!b)
        return 1;
    else if(b&1)
        return (1ll*exp(a,b-1)*a)%mod;
    else{
        int aux=exp(a,b>>1);
        return (1ll*aux*aux)%mod;
    }
}

inline void prec()
{
    fact[0]=1;
    for(int i=1;i<100005;i++)
        fact[i]=(1ll*i*fact[i-1])%mod;

    invfact[100004]=exp(fact[100004],mod-2);
    for(int i=100003;i>=0;i--)
        invfact[i]=(1ll*invfact[i+1]*(i+1))%mod;
}

inline int comb(int n,int k)
{
    return (1ll*(1ll*fact[n]*invfact[n-k])%mod*invfact[k])%mod;
}

int din[1024][1024];

vector<int> special2;
map<int,int> frecv;

signed main()
{
    int n=0,k=0;
    cin>>n>>k;

    int x;
    special.push_back(0);

    while(n--){
        cin>>x;

        if(lucky(x)){
            special.push_back(x);
            frecv[x]++; //
        }
        else
            normal.push_back(x);
    }

    sort(special.begin(),special.end());

    special2.push_back(0);
    for(int i=1;i<special.size();i++)
        if(special[i]!=special[i-1])
            special2.push_back(special[i]);

    din[0][0]=1;

    for(int i=1;i<special2.size();i++){
        din[i][0]=1;
        for(int k=1;k<1024;k++){
            din[i][k]=((1ll*frecv[special2[i]]*din[i-1][k-1])%mod+din[i-1][k])%mod;
        }
    }

    prec();


    int ans=0;
    for(int i=0;i<=k;i++)
        if(i<=normal.size() && k-i<special2.size())
            ans=(ans+(1ll*comb(normal.size(),i)*din[special2.size()-1][k-i])%mod)%mod;

    cout<<ans<<'\n';
    return 0;
}