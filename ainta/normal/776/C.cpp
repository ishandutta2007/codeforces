#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
map<long long, int>Map;
int n, K;
long long s, res, t;
int main(){
    int a, i;
    scanf("%d%d",&n,&K);
    Map[0] = 1;
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        s += a;
        if(K==1){
            res += Map[s-1];
        }
        else if(K==-1){
            res += Map[s-1] + Map[s+1];
        }
        else{
            t = 1;
            while(1){
                res += Map[s-t];
                t*=K;
                if(t > 1e15 || -t > 1e15)break;
            }
        }
        Map[s]++;
    }
    printf("%lld\n",res);
}