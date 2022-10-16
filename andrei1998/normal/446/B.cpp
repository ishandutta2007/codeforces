#include <iostream>
#include <queue>

#define NMAX 1005
#define KMAX 1000005
#define lint long long int
using namespace std;

lint lin[NMAX];
lint col[NMAX];

lint smax_lin[KMAX];
lint smax_col[KMAX];

priority_queue<lint> coada;
int main()
{
    int n,m,k,p,aux;
    cin>>n>>m>>k>>p;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>aux;
            lin[i]+=aux;
            col[j]+=aux;
        }

    for(int i=1;i<=n;i++)
        coada.push(lin[i]);

    for(int i=1;i<=k;i++){
        smax_lin[i]=coada.top();
        coada.pop();
        coada.push(smax_lin[i]-1ll*m*p);

        smax_lin[i]+=smax_lin[i-1];
    }

    while(!coada.empty())
        coada.pop();

    for(int i=1;i<=m;i++)
        coada.push(col[i]);

    for(int i=1;i<=k;i++){
        smax_col[i]=coada.top();
        coada.pop();
        coada.push(smax_col[i]-1ll*n*p);

        smax_col[i]+=smax_col[i-1];
    }

    lint maxim=smax_lin[0]+smax_col[k];
    for(int i=1;i<=k;i++){
        lint aux=smax_lin[i]+smax_col[k-i]-1ll*i*p*(k-i);

        if(aux>maxim)
            maxim=aux;
    }

    cout<<maxim<<'\n';
    return 0;
}