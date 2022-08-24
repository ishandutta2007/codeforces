#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int main(){
    int i, M = 25, a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        M = max(M,a);
    }
    printf("%d\n",M-25);
}