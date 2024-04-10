#include<cstdio>
#include<cstring>
#include<vector>
#define N 1001000
using namespace std;
int pre[N],next[N];
int main(){
    int n,a,b,i,j;
    bool flag=true;
    memset(pre,-1,sizeof(pre));
    memset(next,-1,sizeof(next));
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        next[a]=b;
        pre[b]=a;
    }
    for(i=0;i<N;i++){
        if(next[i]>=0&&pre[i]==-1) break;
    }
    j=next[0];
    while(i>0||j>0){
        if(!flag) printf(" ");
        else flag=false;
        if(j>0){
            printf("%d %d",i,j);
            i=next[i];
            j=next[j];
        }
        else{
            printf("%d",i);
            i=next[i];
        }
    }
    putchar('\n');
    return 0;
}