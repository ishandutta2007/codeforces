#include <iostream>
#include <bitset>

#define MAXN 1000005
using namespace std;

bitset<MAXN> viz;
int s_part[MAXN];

inline void erat()
{
    for(int i=3;i<=1005;i+=2)
        if(!viz[i])
            for(int j=i*i;j<=MAXN;j+=i)
                viz[j]=1;

    s_part[2]=1;
    for(int i=3;i<=MAXN;i+=2)
        if(!viz[i])
            s_part[i]=1;

    for(int i=1;i<=MAXN;i++)
        s_part[i]+=s_part[i-1];
}

inline int cate(int i,int j)
{
    return (s_part[j]-s_part[i-1]);
}

bool ver(int a,int b,int k,int l)
{
    bool ok=true;
    for(int x=a;x<=(b-l+1);x++)
        if(cate(x,x+l-1)<k){
            ok=false;
            break;
        }

    return ok;
}

int main()
{
    erat();

    int a,b,k;
    cin>>a>>b>>k;

    int st=1;
    int dr=b-a+1;
    int mijl=(st+dr)>>1;
    int rasp=1000005;

    while(st<=dr){
        if(ver(a,b,k,mijl)){
            rasp=mijl;
            dr=mijl-1;
        }
        else
            st=mijl+1;

        mijl=(st+dr)>>1;
    }

    if(rasp==1000005)
        cout<<"-1\n";
    else
        cout<<rasp<<'\n';

    return 0;
}