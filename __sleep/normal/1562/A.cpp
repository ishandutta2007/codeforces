#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500005;
int n,t,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        int l,r,mid;
        scanf("%d%d",&l,&r);
        mid=max(l,r/2+1);
        printf("%d\n",r-mid);
    }
    return 0;
}