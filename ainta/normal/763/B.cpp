#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n;
int main(){
    int i, x1, x2, y1, y2;
    scanf("%d",&n);
    printf("YES\n");
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int c = 1;
        if(abs(x1)%2) c += 2;
        if(abs(y1)%2) c += 1;
        printf("%d\n",c);
    }
}