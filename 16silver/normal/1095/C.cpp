#include <cstdio>
int num[30], idx;
int main(){
    int n,k,cnt=0;
    scanf("%d%d",&n,&k);
    if(n<k){
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<30;i++){
        if(n&(1<<i)){
            num[i] = 1;
            cnt++;
            idx=i;
        }
        else num[i] = 0;
    }
    if(cnt>k){
        printf("NO\n");
        return 0;
    }
    while(cnt<k){
        num[idx]--;
        num[idx-1]+=2;
        if(num[idx]==0) idx--;
        cnt++;
    }
    printf("YES\n");
    for(int i=0;i<=idx;i++){
        for(int j=0;j<num[i];j++){
            printf("%d ",1<<i);
        }
    }
}