#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int main(){
    int i, TC;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n);
        if(n>6+10+14){
            puts("YES");
            if(n!=36&&n!=40&&n!=44){
                printf("%d %d %d %d\n",6,10,14,n-30);
            }
            else{
                printf("%d %d %d %d\n",6,10,15,n-31);
            }
        }
        else{
            puts("NO");
        }
    }   
}