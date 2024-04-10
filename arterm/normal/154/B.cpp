#include <iostream>

#define M 100100

using namespace std;

long p[M],t[M];
bool u[M];

void pre(void){
    for (long i=1; i<M; ++i){
        p[i]=1;
        t[i]=0;
        u[i]=0;
    }

    for (long i=2; i<M; ++i)
    if (p[i]==1)
    for(long j=i; j<M ;j+=i)
    p[j]=i;

}

void del(long x){
    u[x]=0;
    while (x!=1){
        t[p[x]]=0;
        x/=p[x];
    }
}

long add(long x){
    long y=x;

    while (y!=1)
    if (t[p[y]]!=0)
    return t[p[y]];
    else
    y/=p[y];

    y=x;
    u[x]=1;
    while (y!=1){
        t[p[y]]=x;
        y/=p[y];
    }
    return 0;
}

int main()
{
    long n,m,a,s;
    char ch;
    pre();
    cin>>n>>m;
    for (long i=0; i<m; ++i){
        cin>>ch>>a;
        if (ch=='+')
        if (u[a])
        cout<<"Already on\n";
        else{
            s=add(a);
            if (s==0)
            cout<<"Success\n";
            else
            cout<<"Conflict with "<<s<<"\n";
        }

        if (ch=='-')
        if (!u[a])
        cout<<"Already off\n";
        else{
            del(a);
            cout<<"Success\n";
        }

    }
    return 0;
}