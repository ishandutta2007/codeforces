#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define fuc 1000100
int a[fuc][2],n;
int main(){
   scanf("%d",&n);
   for(int i=0,j;i<n;++i) scanf("%d",&j),a[j][0]++,a[j][1]=i;
   int maxp=0;
   for(int i=0;i<fuc;++i) if(a[i][0]>maxp) maxp=a[i][0];
   int mind=100010001,mid=0;
   for(int i=0;i<fuc;++i) if(a[i][0]==maxp && a[i][1]<mind) mind=a[i][1],mid=i;
   printf("%d",mid);
   return 0;
}