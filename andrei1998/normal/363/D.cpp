#include <iostream>
#include <algorithm>
#include <utility>

#define lint long long int
using namespace std;

lint n,m;
lint a;

lint b[2000005];
lint p[2000005];

inline pair<bool,lint> ok(lint m)
{
    lint a;
    a=(::a);
    lint folosit=0;

    for(lint i=n,j=m;i>=1 && j>=1;i--,j--)
        if(b[i]>=p[j]){
            folosit+=p[j];
        }
        else{
            folosit+=b[i];
            a-=(p[j]-b[i]);
        }
    return make_pair(a>=0,max(0ll,folosit-a));
}

int main()
{
    cin>>n>>m>>a;

    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=m;i++)
        cin>>p[i];

    sort(b+1,b+n+1);
    sort(p+1,p+m+1);

    //Cautam binar ultima bicicleta pe care o putem lua
    lint st=1;
    lint dr=min(n,m);
    lint mijl=(st+dr)>>1;

    lint rasp=0; //Mijl
    lint val=0;

    while(st<=dr){
        pair<bool,lint> aux=ok(mijl);

        if(aux.first){
            rasp=mijl;
            val=aux.second;

            st=mijl+1;
        }
        else
            dr=mijl-1;
        mijl=(st+dr)>>1;
    }
    cout<<rasp<<' '<<val<<'\n';

    return 0;
}