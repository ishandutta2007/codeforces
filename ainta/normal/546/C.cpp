#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
map<long long,int>Map;
int w1[10], c1, w2[10], c2, n;
int main(){
    int i, Res = 0, t1 ,t2;
    long long a = 0;
    scanf("%d",&n);
    scanf("%d",&c1);
    for(i=0;i<c1;i++){
        scanf("%d",&w1[i]);
    }
    scanf("%d",&c2);
    for(i=0;i<c2;i++){
        scanf("%d",&w2[i]);
    }
    while(c1!=n && c2!=n){
        a = 0;
        for(i=0;i<c1;i++){
            a*=11;
            a+=w1[i];
        }
        for(i=0;i<c2;i++){
            a*=11;
            a+=w2[i];
        }
        a*=11;a+=c1;
        if(Map[a])break;
        Map[a] = 1;
        Res++;
        t1 = w1[0], t2 = w2[0];
        for(i=0;i<c1-1;i++)w1[i]=w1[i+1];
        for(i=0;i<c2-1;i++)w2[i]=w2[i+1];
        c1--,c2--;
        if(t1 < t2){
            w2[c2++] = t1;
            w2[c2++] = t2;
        }
        else{
            w1[c1++] = t2;
            w1[c1++] = t1;
        }
    }
    if(c1!=n &&c2!=n){
        printf("-1\n");
        return 0;
    }
    printf("%d ",Res);
    if(c1==n)printf("1\n");
    else printf("2\n");
}