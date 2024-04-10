#include <iostream>

#define M 307
#define T 303

using namespace std;

//ifstream cin ("input.txt");
//ofstream cout("output.txt");

long a[M][M],b[M],n,t[M],bst,sec,w[M];

void read(void){
    cin>>n;
    for (long i=1; i<=n; ++i)
    for (long x,j=1; j<=n; ++j){
        cin>>x;
        a[i][x]=j;
    }
    for (long x,i=1; i<=n; ++i){
        cin>>x;
        b[x]=i;
        a[i][T]=T;
        t[i]=T;
    }
    bst=sec=T;
    b[T]=T;
}

void kill(void){
    for (long i=1; i<=n; ++i){

        if (b[i]<b[bst]){
            sec=bst;
            bst=i;
        }
        else
        if (b[i]<b[sec])
        sec=i;

        for (long j=1; j<=n; ++j){
            if (bst!=j && a[j][bst]<a[j][t[j]])
            t[j]=bst,w[j]=i;
            if (sec!=j && bst==j)
            if (a[j][sec]<a[j][t[j]])
            t[j]=sec,w[j]=i;
        }

    }
    for (long j=1; j<=n; ++j)
    cout<<w[j]<<" ";
}

int main()
{
    read();
    kill();
    return 0;
}