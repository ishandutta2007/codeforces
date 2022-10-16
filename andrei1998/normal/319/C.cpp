#include <iostream>
#include <algorithm>

#define NMAX 100005
#define lint long long int
#define inf 1500000000000000005ll
using namespace std;

int a[NMAX]; //H
int b[NMAX]; //Cost
lint din[NMAX]; //Costul minim pentru a dobora primii i copaci pornind fara benzina

struct dreapta //ax+b
{
    lint a; //Mergea si int
    lint b;

    dreapta(lint x=0,lint y=0): a(x),b(y) {}
};

dreapta stiva[NMAX];
int poz;

inline void add(dreapta x)
{
    //cout<<"add "<<x.a<<' '<<x.b<<endl;
    while(poz>=2)
        if((1.0*x.b-stiva[poz].b)/(stiva[poz].a-x.a)<=(1.0*stiva[poz].b-stiva[poz-1].b)/(stiva[poz-1].a-stiva[poz].a))
            poz--;
        else
            break;
    stiva[++poz]=x;
}

inline int ok(int unde,lint x)
{
    if(poz==1)
        return 0;

    /*if(unde==1){
        if(x*(stiva[unde].a-stiva[unde+1].a)<=(stiva[unde+1].b-stiva[unde].b))
            return 0;
        return 1;
    }
    else if(unde==poz){
        if(x*(stiva[unde].a-stiva[unde-1].a)>=(stiva[unde-1].b-stiva[unde].b))
            return 0;
        return -1;
    }

    if(x*(stiva[unde].a-stiva[unde-1].a)>=(stiva[unde-1].b-stiva[unde].b) && x*(stiva[unde].a-stiva[unde+1].a)<=(stiva[unde+1].b-stiva[unde].b))
        return 0;
    else if(x*(stiva[unde].a-stiva[unde-1].a)<(stiva[unde-1].b-stiva[unde].b))
        return -1;
    return 1;*/

    double x1,x2;
    if(unde==1){
        x1=-inf;
        x2=(1.0*stiva[unde+1].b-stiva[unde].b)/(stiva[unde].a-stiva[unde+1].a);
    }
    else if(unde==poz){
        x1=(1.0*stiva[unde-1].b-stiva[unde].b)/(stiva[unde].a-stiva[unde-1].a);
        x2=inf;
    }
    else{
        x1=(1.0*stiva[unde-1].b-stiva[unde].b)/(stiva[unde].a-stiva[unde-1].a);
        x2=(1.0*stiva[unde+1].b-stiva[unde].b)/(stiva[unde].a-stiva[unde+1].a);
    }

    if(x>=x1 && x<=x2)
        return 0;
    if(x<x1)
        return -1;
    return 1;
}

lint bs(lint x)
{
    int st=1;
    int dr=poz;
    int mijl=(1+poz)>>1;

    while(st<=dr){
        int aux=ok(mijl,x);
        if(!aux)
            return (1ll*stiva[mijl].a*x+stiva[mijl].b);
        else if(aux==1)
            st=mijl+1;
        else
            dr=mijl-1;

        mijl=(st+dr)>>1;
    }

    return -1; //Error
}

int main()
{
    int n=1;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];

    a[1]--; //Plecam fara benzina
    din[1]=0;

    add(dreapta(b[1],0));
    for(int i=2;i<=n;i++){
        din[i]=bs(a[i]);
        //cout<<din[i]<<endl;

        //din[i]=inf;

        //for(int j=1;j<i;j++)
        //    din[i]=min(din[i],din[j]+1ll*a[i]*b[j]);
        if(i<n)
            add(dreapta(b[i],din[i]));
        //cout<<din[i]<<endl;
    }

    cout<<din[n]<<'\n';
    return 0;
}