#include <cstdio>
#include <memory>
#define maxn 100002
using namespace std;
int n,a[maxn],res;
void swap(int i,int j){int t=a[i];a[i]=a[j];a[j]=t;}
bool isInc(){for(int i=2;i<=n;i++)if(a[i-1]>a[i])return false;return true;}
bool isDec(){for(int i=2;i<=n;i++)if(a[i-1]<a[i])return false;return true;}
bool isSorted(){return (isDec()||isInc());}
bool isOneval(){for(int i=2;i<=n;i++)if(a[i-1]!=a[i])return false; return true;}
int main(){
    int i,j;res=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    if(isOneval()){
                   printf("-1");
                   return 0;
    }
    for (i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    if(a[i]!=a[j]){
                   swap(i,j);
                   if(isSorted()==false){printf("%d %d",i,j);return 0;}
                   swap(i,j);
                   }
                   printf("-1");
                   return 0;
    }