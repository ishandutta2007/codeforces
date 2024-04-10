#include <iostream>

#define NMAX 200005
using namespace std;

int n,w,m;
int v[NMAX];

int aux[NMAX];
int aux2[NMAX];

bool ok(int minim){
    int i;
    int m=(::m);

    for(i=1;i<=(2*n);i++)
        aux[i]=v[i],aux2[i]=0;

    for(i=1;i<=n;i++){
        aux2[i]+=aux2[i-1];

        if((aux2[i]+aux[i])<minim){
            if((minim-aux2[i]-aux[i])>m)
                return 0;
            m-=(minim-aux2[i]-aux[i]);

            aux2[i+w]-=(minim-aux2[i]-aux[i]);
            aux2[i]+=(minim-aux2[i]-aux[i]);
        }
    }

    return 1;
}

int main()
{
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++)
        cin>>v[i];

    int st=1;
    int dr=1000100005;
    int mijl=(st+dr)>>1;
    int rasp=1;

    while(st<=dr){
        if(ok(mijl)){
            st=mijl+1;
            rasp=mijl;
        }
        else
            dr=mijl-1;

        mijl=(st+dr)>>1;
    }

    cout<<rasp<<'\n';
    return 0;
}