#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[101000], S[101000];
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    sort(w+1,w+n+1);
    int ck=0;
    for(i=1;i<=n;i++){
        S[i]=S[i-1]+w[i];
        if(S[i]==0)ck=1;
    }
    if(!ck){
        puts("YES");
        for(i=1;i<=n;i++)printf("%d ",w[i]);
        puts("");
        return;
    }
    reverse(w+1,w+n+1);
    ck=0;

    for(i=1;i<=n;i++){
        S[i]=S[i-1]+w[i];
        if(S[i]==0)ck=1;
    }
    if(!ck){
        puts("YES");
        for(i=1;i<=n;i++)printf("%d ",w[i]);
        puts("");
        return;
    }
    puts("NO");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}