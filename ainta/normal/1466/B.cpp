#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int n, C[201000];
void Solve(){
    int i;
    scanf("%d",&n);
    int M = 2*n+1;
    for(i=1;i<=M;i++)C[i]=0;
    for(i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        C[a]++;
    }
    int pv = 0, s = 0;
    int res=0;
    for(i=1;i<=M;i++){
        if(!C[i]){
            if(!s){
                pv = i;
                continue;
            }
            else{
                if((i-pv-1)!=s){
                    res++;
                }
            }
            s=0;
            pv=i;
        }
        else{
            res++;
            s+=C[i];
        }
    }
    printf("%d\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}