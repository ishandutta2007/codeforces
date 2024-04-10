#include <cstdio>
int a[200001][2], b[200001][2], ans[200001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        b[i][0] = -1;
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i][0],&a[i][1]);
        if(b[a[i][0]][0] == -1) b[a[i][0]][0] = i;
        else b[a[i][0]][1] = i;
        if(b[a[i][1]][0] == -1) b[a[i][1]][0] = i;
        else b[a[i][1]][1] = i;
    }
    if(n==3){
        printf("1 2 3\n");
        return 0;
    }
    int st = 1, bk1, bk2;
    if(a[b[st][0]][0] == b[st][1] || a[b[st][0]][1] == b[st][1]) bk1 = b[st][1];
    else bk1 = b[st][0];
    ans[0] = 1;
    for(int j=1;j<n;j++){
        if(b[st][0] == bk1){
            bk2 = b[st][1];
        }
        else{
            bk2 = b[st][0];
        }
        ans[j] = bk1;
        st = bk1;
        bk1 = bk2;
    }
    for(int i=n-1;i>=0;i--) printf("%d ",ans[i]);
}