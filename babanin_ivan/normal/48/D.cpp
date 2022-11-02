#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int b[100100],a[100100],c[100100];

void printerror(){
    printf("-1 \n");
    exit(0);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    //for (int i=0;i<=100000;++i)
    //  b[i]=0;
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        ++b[a[i]];
    }
    int m=0;
    for (int i=100000;i>0;--i){
        if (m==0 && b[i]==0)
            continue;
        if (b[i]<m)
            printerror();
        if (b[i]==m)
            c[i]=m;
        if (b[i]>m){
            m=b[i];
            c[i]=b[i];
        }
    }
    printf("%d\n",m);
    for (int i=0;i<n;++i){
        printf("%d ",c[a[i]]);
        --c[a[i]];
    }
}