#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int main(){
    int i, TC;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n);
        for(i=0;i<n-(n+3)/4;i++)printf("9");
        for(i=0;i<(n+3)/4;i++)printf("8");
        puts("");
    }
}