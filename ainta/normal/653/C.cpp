#include<stdio.h>
#include<algorithm>
using namespace std;
int w[201000], n, cnt, Res, cc[201000];
int Do(int a, int b){
    int c1 = 0, c2 = 0, TT[5], cc = 0, i;
    if(a-1>=1)TT[cc++] = a-1;
    if(a<=n)TT[cc++] = a;
    if(b-1!=a && b-1>=1)TT[cc++] = b-1;
    if(b!=a-1 && b<=n)TT[cc++] = b;
    for(i=0;i<cc;i++){
        if(TT[i]%2==1 && w[TT[i]] >= w[TT[i]+1])c1++;
        if(TT[i]%2==0 && w[TT[i]] <= w[TT[i]+1])c1++;
    }
    swap(w[a],w[b]);
    for(i=0;i<cc;i++){
        if(TT[i]%2==1 && w[TT[i]] >= w[TT[i]+1])c2++;
        if(TT[i]%2==0 && w[TT[i]] <= w[TT[i]+1])c2++;
    }
    swap(w[a],w[b]);
    return c1-c2;
}
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<n;i++){
        if(i%2==1 && w[i]>=w[i+1])cc[i]++;
        if(i%2==0 && w[i]<=w[i+1])cc[i]++;
    }
    for(i=1;i<=n;i++){
        if(cc[i])cnt++;
    }
    if(cnt > 5){
        printf("0\n");
        return 0;
    }
    for(i=1;i<=n;i++){
        if(!cc[i] && !cc[i-1])continue;
        for(j=1;j<=n;j++){
            if(j==i)continue;
            if( (cc[j] || cc[j-1]) && j<i)continue;
            if(Do(i,j) == cnt)Res++;
        }
    }
    printf("%d\n",Res);
}