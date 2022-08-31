#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100001],b[100001];
int main()
{
    int n,m,i,K;
    scanf("%d%d%d",&n,&m,&K);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<m;i++)scanf("%d",&b[i]);
    if(n>m){
        printf("YES\n");
        return 0;
    }
    sort(a,a+n);
    sort(b,b+m);
    for(i=0;i<n;i++)if(a[i]>b[m-n+i])break;
    if(i==n)printf("NO\n");
    else printf("YES\n");
}