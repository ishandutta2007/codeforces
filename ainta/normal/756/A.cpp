#include<stdio.h>
int n, w[201000], odd, res;
bool v[201000];
int main(){
    int i, a, cnt = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        odd^=a;
    }
    for(i=1;i<=n;i++){
        if(!v[i]){
            a = i;
            while(1){
                v[a] = true;
                a = w[a];
                if(a == i)break;
            }
            cnt++;
        }
    }
    if(cnt >= 2)res = cnt;
    printf("%d\n",res + (odd^1));
}