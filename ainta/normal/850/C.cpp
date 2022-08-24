#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n, p[11000], w[110], cnt;
int D[1010000];
map<int,int>Map;
void Calc(int a){
    int i;
    for(i=2;i*i<=a;i++){
        if(a%i==0){
            if(!Map.count(i)){
                Map[i] = 1;
                p[++cnt] = i;
            }
            while(a%i==0){
                a/=i;
            }
        }
    }
    if(a!=1){
        if(!Map.count(a)){
            Map[a] = 1;
            p[++cnt] = a;
        }
    }
}
int res, v[42];
int Gap(int a){
    if(a<=1000000)return D[a];
    int j, T[40] = {0};
    for(j=0;j<30;j++){
        int t = (a & ((1<<j) - 1)) | (a >> (j+1));
        if(a!=t){
            T[Gap(t)] = 1;
        }
    }
    for(j=0;T[j];j++);
    return j;
}
int main(){
    int i, a, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        Calc(w[i]);
    }
    
    for(i=1;i<=1000000;i++){
        for(j=0;j<22;j++)v[j]=0;
        for(j=0;j<22;j++){
            int t = (i & ((1<<j) - 1)) | (i >> (j+1));
            if(i!=t)v[D[t]] = 1;
        }
        for(j=0;j<22;j++)if(!v[j])break;
        D[i] = j;
    }
    
    for(i=1;i<=cnt;i++){
        int s = 0;
        for(j=1;j<=n;j++){
            int a = w[j], c = 0;
            while(a%p[i]==0){
                a/=p[i], c++;
            }
            if(c)s |= (1<<(c-1));
        }
        res ^= Gap(s);
    }
    if(res)printf("Mojtaba\n");
    else printf("Arpa\n");
}