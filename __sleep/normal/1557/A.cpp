#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300003;
int t,n,a[N],mx;
double sum=0;
int main(){
    scanf("%d",&t);
    while(t--){
        sum=0; mx=-2e9;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            if(mx<a[i]) mx=a[i];
            sum+=a[i];
        }
        double ans=mx+(sum-mx)/(n-1);
        printf("%.8f\n",ans);
    }
    return 0;
}