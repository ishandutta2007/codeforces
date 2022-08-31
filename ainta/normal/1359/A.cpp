#include<cstdio>
#include<algorithm>
using namespace std;
int w[1100];
int main(){
    int TC, n, m, K, i;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d%d",&n,&m,&K);
        for(i=0;i<n;i++){
            if(i<m)w[i]=1;
            else w[i]=0;
        }
        int s1=0, ss=m;
        for(i=0;i<n/K;i++){
            s1+=w[i];
        }
        ss-=s1;
        ss=(ss+K-2)/(K-1);
        printf("%d\n",s1-ss);
    }
}