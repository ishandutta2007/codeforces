#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int v[10100], U[1010], n;
void Query(vector<int>V){
    int sz=V.size();
    printf("%d ",sz);
    for(auto &t : V){
        printf("%d ",t);
        v[t]=1;
    }
    puts("");
    fflush(stdout);
    int a;
    scanf("%d",&a);
    for(int i=0;i<sz;i++){
        int t=a+i;
        if(t>n)t-=n;
        v[t]=0;
    }
}
void Go(int a){
    int i, bef = 0;
    for(i=1;i<=n;i++)if(v[i])bef++;
    while(1){
        vector<int>V;
        for(i=1;i<=n;i++){
            if(i%a!=1 && !v[i]){
                V.push_back(i);
            }
        }
        Query(V);
        int aft=0;
        for(i=1;i<=n;i++)if(v[i])aft++;
        if(bef!=aft)break;
    }
}
void Calc(){
    int cur = 0, i;
    while(1){
        int ck = 0;
        for(i=1;i<=n-cur;i++){
            int z = cur+i;
            if(z*i <= n*(i-1)){
                Go(i);
                cur=0;
                ck=1;
                for(int j=1;j<=n;j++)if(v[j])cur++;
                break;
            }
        }
        if(!ck)break;
    }
}
int main(){
    scanf("%d",&n);
    Calc();
    puts("0");
    fflush(stdout);
}