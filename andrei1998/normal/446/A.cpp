#include <iostream>
#include <algorithm>

#define NMAX 100005
using namespace std;

int st[NMAX];
int dr[NMAX];
int v[NMAX];

int main()
{
    int n=0;
    cin>>n;

    if(n<=2){
        cout<<n<<'\n';
        return 0;
    }

    for(int i=1;i<=n;i++)
        cin>>v[i];

    st[1]=1;
    for(int i=2;i<=n;i++)
        if(v[i]>v[i-1])
            st[i]=st[i-1]+1;
        else
            st[i]=1;

    dr[n]=1;
    for(int i=n-1;i>=1;i--)
        if(v[i]<v[i+1])
            dr[i]=dr[i+1]+1;
        else
            dr[i]=1;

    int maxim=1;
    maxim=max(maxim,max(st[n-1],dr[2])+1);

    for(int i=2;i<n;i++){
        int aux=-1;
        if(v[i-1]+1<v[i+1])
            aux=1+st[i-1]+dr[i+1];
        else
            aux=max(dr[i+1],st[i-1])+1;

        if(aux>maxim)
            maxim=aux;
    }

    cout<<maxim<<'\n';
    return 0;
}