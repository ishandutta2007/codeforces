#include<cstdio>
#include<algorithm>
long long n,k,b[10004],a[10004],aa[]={0,9,7,3,4,5,12,2,8,1,10,11,6};
inline long long ask(int i,int j){
    printf("or %d %d\n",i,j);
    printf("and %d %d\n",i,j);
    fflush(stdout);
    long long x,y;
    scanf("%lld%lld",&x,&y);
    return x+y;
    // return aa[i]+aa[j];
}
int main(){
    scanf("%lld%lld",&n,&k);
    int m=3;
    for(int i=1;i<=m;i++)
        b[i]=ask(i,i%m+1);
    for(int i=1;i<=m;i++)
        a[1]+=((i&1)?1:-1)*b[i];
    a[1]/=2;
    for(int i=2;i<=m;i++)
        a[i]=b[i-1]-a[i-1];
    for(int i=4;i<=n;i++)
        a[i]=ask(i,1)-a[1];
    std::sort(a+1,a+n+1);
    printf("finish %lld\n",a[k]);
    return 0;
}

// b[i]=a[i]+a[n];
/*
7 6
 7 0 10 0 6 0 5 0 8 0 9 0 5 
*/