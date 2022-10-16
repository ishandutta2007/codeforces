#include <iostream>
#include <map>
#include <bitset>

#define NMAX 100005
using namespace std;

bool sol;
int tata[NMAX];
int h[NMAX];
bitset<NMAX> fixat;
bitset<NMAX> val;

int f(int x){
    if(x!=tata[x])
        tata[x]=f(tata[x]);
    return tata[x];
}

inline void unite(int a,int b){
    a=f(a);b=f(b);

    if(a==b)
        return;

    if(h[a]>h[b])
        tata[b]=a;
    else{
        if(h[a]==h[b])
            h[b]++;
        tata[a]=b;
    }
}

map<int,int> harta;
int v[NMAX];

inline void fixeaza(int nod,int x){
    nod=f(nod);
    if(!fixat[nod]){
        fixat[nod]=1;
        val[nod]=x;
    }
    else if(val[nod]!=x)
        sol=false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0,a=0,b=0;
    cin>>n>>a>>b;

    sol=true;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        harta[v[i]]=i;
        tata[i]=i;
        h[i]=1;
    }

    for(int i=1;i<=n;i++){
        if(harta.count(a-v[i]))
            unite(i,harta[a-v[i]]);
        if(harta.count(b-v[i]))
            unite(i,harta[b-v[i]]);
    }

    for(int i=1;i<=n;i++){
        if(!harta.count(a-v[i]))
            fixeaza(i,1);
        if(!sol)
            break;

        if(!harta.count(b-v[i]))
            fixeaza(i,0);
        if(!sol)
            break;
    }

    if(!sol){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";

    cout<<val[f(1)];
    for(int i=2;i<=n;i++)
        cout<<' '<<val[f(i)];
    cout<<'\n';

    return 0;
}