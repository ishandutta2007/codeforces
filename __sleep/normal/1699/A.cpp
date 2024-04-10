#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n&1) {puts("-1"); continue;}
        printf("%d %d %d\n",0,0,n/2);
    }
    return 0;
}