#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[201000], C[201000];
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)C[i]=0;
    for(i=0;i<n;i++){
        scanf("%d",&w[i]);
        w[i]+=i;
        w[i]%=n;
        if(w[i]<0)w[i]+=n;
        C[w[i]]++;
    }
    for(i=0;i<n;i++){
        if(C[i]!=1){
            puts("NO");
            return;
        }
    }
    puts("YES");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}