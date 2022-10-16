#include <iostream>
#include <vector>

#define mod 1000000007
#define NMAX 100005
using namespace std;

vector<int> graf[NMAX];

int exp(int a,int b){
    if(!b)
        return 1;
    else if(b&1)
        return (1ll*a*exp(a,b-1))%mod;
    else{
        int aux=exp(a,b>>1);
        return (1ll*aux*aux)%mod;
    }
}

inline int inv(int x){
    return exp(x,mod-2);
}

int din[NMAX][2];
int cul[NMAX];

void dfs(int nod,int father){
    int s=1;
    for(vector<int>::iterator it=graf[nod].begin();it!=graf[nod].end();it++)
        if((*it)!=father){
            dfs(*it,nod);
            s=(1ll*s*((din[*it][1]+1ll*din[*it][0])%mod))%mod;
        }

    if(!cul[nod]){
        din[nod][0]=s;

        for(vector<int>::iterator it=graf[nod].begin();it!=graf[nod].end();it++)
            if((*it)!=father)
                din[nod][1]=((long long int)din[nod][1]+((1ll*s*din[*it][1])%mod*inv((din[*it][1]+1ll*din[*it][0])%mod)))%mod;
    }
    else{
        din[nod][0]=0;
        din[nod][1]=s;
    }
}

int p[NMAX];

int main()
{
    int n=0;
    cin>>n;

    for(int i=0;i<n-1;i++)
        cin>>p[i];

    for(int i=0;i<n-1;i++){
        graf[p[i]+1].push_back(i+2);
        graf[i+2].push_back(p[i]+1);
    }

    for(int i=1;i<=n;i++)
        cin>>cul[i];

    dfs(1,0);
    cout<<din[1][1]<<endl;

    return 0;
}