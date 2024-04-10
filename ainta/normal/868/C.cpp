#include<cstdio>
#include<algorithm>
using namespace std;
int n, C[16], K;
int main(){
    int i, j, a;
    scanf("%d%d",&n,&K);
    for(i=0;i<n;i++){
        int s = 0;
        for(j=0;j<K;j++){
            scanf("%d",&a);
            s += (a<<j);
        }
        if(s==0){
            puts("YES");
            return 0;
        }
        C[s]++;
    }
    for(i=0;i<(1<<K);i++){
        for(j=0;j<(1<<K);j++){
            if(i&j)continue;
            if(C[i]&&C[j]){
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
}