#include <iostream>
#include <algorithm>

using namespace std;

int n;
int v[55];

inline int calc () {
    int ans=0;

    for(int i=1;i<=n;i++)
        for(int j=i,minim=v[i];j<=n;j++,minim=min(minim,v[j]))
            ans+=minim;

    return ans;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        v[i]=i;

    int maxim=-1;
    int aux;
    do {
        aux=calc();
        if(aux>maxim)
            maxim=aux;

    } while(next_permutation(v+1,v+n+1));

    for(int i=1;i<=n;i++)
        v[i]=i;

    int m;
    cin>>m;

    int x=0;
    do {
        if(calc()==maxim) {
            x++;
            if(m==x)
                break;
        }
    } while(next_permutation(v+1,v+n+1));

    for(int i=1;i<=n;i++)
        cout<<v[i]<<' ';
    cout<<endl;

    return 0;
}