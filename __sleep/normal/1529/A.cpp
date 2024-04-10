#include<cstdio>
const int N=100005;
int t,n,a[N];
int main(){
    scanf("%d",&t);
    int mn,num,tmp;
    while(t--){
        scanf("%d",&n);
        mn=1e9; num=0;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            if(tmp<mn) mn=tmp,num=1;
            else if(tmp==mn) num++;
        }
        printf("%d\n",n-num);
    }
    return 0;
}