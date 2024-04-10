#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n/2;i++){
            for(int j=0;j<m/2;j++){
                if((i+j)&1) printf("0 1 ");
                else printf("1 0 ");
            }
            puts("");
            for(int j=0;j<m/2;j++){
                if(!((i+j)&1)) printf("0 1 ");
                else printf("1 0 ");
            }
            puts("");
        }
    }
    return 0;
}