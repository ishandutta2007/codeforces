#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[101000], q[101000];
int n;
void Solve(){
    int i, j;
    scanf("%d",&n);
    scanf("%s",p);
    scanf("%s",q);
    for(i=0;i<n;i++){
        if(p[i]>q[i]){
            puts("-1");
            return;
        }
    }
    int res=0;
    for(i=0;i<25;i++){
        int Mn = 1e9;
        for(j=0;j<n;j++){
            if(p[j]==i+'a' && p[j]!=q[j]){
                if(Mn>q[j])Mn=q[j];
            }
        }
        if(Mn>8e8)continue;
        res++;
        for(j=0;j<n;j++){
            if(p[j]==i+'a' && p[j]!=q[j]){
                p[j]=Mn;
            }
        }
    }
    printf("%d\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}