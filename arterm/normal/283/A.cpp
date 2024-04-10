#include <cstdio>

#define M 200200

using namespace std;

int n=1;
long long x[M],a[M],s=0;

void first(void){
    int k,y;
    scanf("%d%d",&k,&y);
    x[k]+=y;
    s+=(y*k);
}

void second(void){
    int y;
    scanf("%d",&y);
    n++;
    a[n]=y;
    s+=y;
}

void third(void){
    s=s-a[n]-x[n];
    x[n-1]+=x[n];
    x[n]=a[n]=0;
    n--;
}

void kill(void){
    int m;
    scanf("%d",&m);
    for (int t,i=0; i<m; ++i){
        scanf("%d",&t);
        switch (t){
            case 1:first();break;
            case 2:second();break;
            case 3:third();break;
        }
        printf("%.9lf\n",s*1.0/n);
    }
}

int main()
{
    kill();
    return 0;
}