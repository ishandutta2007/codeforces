#include <cstdio>
int a[100],c[100],sum,tot,cnt;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        tot += a[i];
    }
    sum = a[0];
    c[0]=1;
    cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]*2<=a[0]){
            c[i]=1;
            sum += a[i];
            cnt++;
        }
    }
    if(sum*2>tot){
        printf("%d\n",cnt);
        for(int i=0;i<n;i++){
            if(c[i]) printf("%d ",i+1);
        }
    }
    else{
        printf("0\n");
    }
}