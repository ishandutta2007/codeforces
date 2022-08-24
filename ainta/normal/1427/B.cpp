#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[201000];
int n, K;
void Solve(){
    int i;
    scanf("%d%d",&n,&K);
    scanf("%s",p+1);
    int ck=0, S1 = 0, S2 = 0;
    int c=0;
    vector<int>V;
    int sum=0;
    for(i=1;i<=n;i++){
        if(p[i]=='W'){
            if(p[i-1]=='W')sum+=2;
            else sum++;
            if(!ck)S1=c;
            else V.push_back(c);
            c=0;
            ck=1;
        }
        if(p[i]=='L'){
            c++;
        }
    }
    if(c){
        if(!ck){
            printf("%d\n",max(K*2-1,0));
            return;
        }
        S2=c;
    }
    sort(V.begin(),V.end());
    int res=0;
    //for(auto &t : V)printf("%d ",t);
   // puts("");
    //printf("%d\n",S1);
    //printf("%d\n",sum);
    for(auto &t : V){
        int x = t;
        while(x>0 && K>0){
            if(x==1)sum+=3;
            else sum+=2;
            x--,K--;
        }
    }
    for(int i=0;i<S2;i++){
        if(K>0){
            sum+=2;
            K--;
        }
    }
    for(int i=0;i<S1;i++){
        if(K>0){
            sum+=2;
            K--;
        }
    }
    printf("%d\n",res+sum);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}