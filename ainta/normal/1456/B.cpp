#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n, w[101000], S[101000];
int main(){
    int i, j, k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n-2;i++){
        if(w[i] > (w[i+1]^w[i+2])){
            puts("1");
            return 0;
        }
        if((w[i]^w[i+1]) > w[i+2]){
            puts("1");
            return 0;
        }
    }
    for(i=1;i<=n;i++){
        S[i]=S[i-1]^w[i];
    }
    int res = 1e9;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            for(k=i+1;k<=n;k++){
                if((S[j]^S[i]) > (S[i]^S[k])){
                    res=min(res, k-j-2);
                }
            }
        }
    }
    if(res>1e8)res=-1;
    printf("%d\n",res);
}