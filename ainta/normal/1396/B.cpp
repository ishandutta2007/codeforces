#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> pii;
int n, w[1010];
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    sort(w+1,w+n+1);
    int s=0;
    for(i=1;i<=n;i++)s+=w[i];
    if(w[n]*2>s){
        puts("T");
        return;
    }
    if(s%2==0){
        puts("HL");
    }
    else{
        puts("T");
    }
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}