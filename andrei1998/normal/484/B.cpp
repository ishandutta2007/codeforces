#include <iostream>
#include <bitset>

#define NMAX 200005
#define VALMAX 2000010
using namespace std;

int v[NMAX];

bitset<VALMAX> viz;
int st[VALMAX];

int det(int mod){
    int maxim=0;
    for(int i=2*mod;i<VALMAX;i+=mod)
        if(st[i]>=i-mod)
            if(st[i]-i+mod>maxim)
                maxim=st[i]-i+mod;

    return maxim;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>v[i];

        viz[v[i]]=1;
    }

    int ante=0;
    for(int i=1;i<VALMAX;i++){
        st[i]=ante;
        if(viz[i])
            ante=i;
    }

    int maxim=0,aux=0;
    for(int i=1;i<VALMAX;i++)
        if(viz[i]){
            aux=det(i);
            if(aux>maxim)
                maxim=aux;
        }

    cout<<maxim<<'\n';
    return 0;
}