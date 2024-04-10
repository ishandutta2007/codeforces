#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[101000];
void Solve(){
    int i;
    scanf("%d",&n);
    int s=0;
    for(i=0;i<n;i++){
        scanf("%d",&w[i]);
        s^=w[i];
    }
    if(s==0){
        puts("DRAW");
        return;
    }
    int M=0;
    for(i=30;i>=0;i--){
        if((s>>i)&1){
            M=i;
            break;
        }
    }
    int ss=0;
    for(i=0;i<n;i++){
        w[i] = ((w[i]>>M)&1);
        ss+=w[i];
    }
    if(ss%4==1)puts("WIN");
    else if(n%2==0)puts("WIN");
    else puts("LOSE");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}