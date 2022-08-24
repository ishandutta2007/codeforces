#include<stdio.h>
#include<algorithm>
using namespace std;
int S[101000], n, K, be, ed, res, mid;
char p[101000];
int main(){
    int i;
    scanf("%d%d",&n,&K);
    scanf("%s",p);
    for(i=0;p[i];i++)S[i+1] = 1-(p[i]-'0');
    for(i=1;i<=n;i++)S[i] += S[i-1];
    be = 0, ed = n;
    while(be<=ed){
        mid = (be+ed)>>1;
        for(i=1;i<=n;i++){
            if(S[i]==S[i-1])continue;
            if(S[min(i+mid,n)] - S[max(i-mid-1,0)] >= K+1)break;
        }
        if(i!=n+1){
            res = mid;
            ed = mid - 1;
        }
        else be = mid +1;
    }
    printf("%d\n",res);
}