#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int TC, n, Left[2010], Right[2010], Up[2010], Down[2010];
char p[2010][2010];
int G(int a){
    return max(n-1-a, a);
}
void Do(int K){
    int i, j;
    for(i=0;i<n;i++){
        Left[i]=1e9, Right[i]=-1e9;
        Up[i]=1e9, Down[i]=-1e9;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(p[i][j]=='0'+K){
                Left[i]=min(Left[i],j);
                Right[i]=max(Right[i],j);
                Up[j]=min(Up[j],i);
                Down[j]=max(Down[j],i);
            }
        }
    }
    int res = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(Down[i] >= Up[j]){
                res = max(res, (Down[i]-Up[j]) * max(G(i),G(j)));
            }
            if(Right[i] >= Left[j]){
                res = max(res, (Right[i]-Left[j]) * max(G(i),G(j)));
            }
        }
    }
    printf("%d ",res);
}
void Solve(){
    int i, j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",p[i]);
    }
    for(i=0;i<10;i++){
        Do(i);
    }
    puts("");
}
int main(){
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}