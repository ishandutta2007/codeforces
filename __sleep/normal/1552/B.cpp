#include<cstdio>
#include<algorithm>
const int N=100005;
struct node{
    int a[5],id;
    inline bool operator <(const node &x){
        int num=0;
        for(int i=0;i<5;i++)
            if(a[i]<x.a[i]) num++;
        return num>=3;
    }
} rk[N];
int n,t;
bool judge(int x){
    for(int i=0;i<n;i++){
        if(i==x) continue;
        if(rk[i]<rk[x]) return false;
    }
    return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            rk[i].id=i+1;
            for(int j=0;j<5;j++){
                scanf("%d",rk[i].a+j);
            }
        }
        // printf("~%d\n",rk[0].id);
        std::sort(rk,rk+n);
        bool flag=0;
        for(int i=0;i<n&&i<50;i++){
            if(judge(i)){
                flag=1;
                printf("%d\n",rk[i].id);
                // for(int j=0;j<5;j++)
                    // printf("%d ",rk[i].a[j]);
                // puts("");
                // if(rk[0]<rk[1]&&rk[0]<rk[2]) puts("!");
                break;
            }
        }
        if(!flag)puts("-1"); 
    }
    return 0;
}