#include<cstdio>
#include<algorithm>
using namespace std;
int n, K;
char p[301000];
void Solve(){
    int i, j, c1 = 0, c2 = 0;
    scanf("%d%d",&n,&K);
    scanf("%s",p);
    for(i=0;i<K;i++){
        int CK=0;
        for(j=i;j<n;j+=K){
            if(p[j]=='0')CK|=1;
            if(p[j]=='1')CK|=2;
        }
        if(CK==3){
            puts("NO");
            return;
        }
        if(CK==1){
            c1++;
        }
        if(CK==2){
            c2++;
        }
    }
    if(c1<=K/2 && c2<=K/2)puts("YES");
    else puts("NO");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}