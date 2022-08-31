#include<stdio.h>
int n, C[1010000], M, be, ed;
int w[101000];
bool Pos(int mid){
    int i, chk = 0;
    for(i=1;i<=mid;i++){
        C[w[i]]++;
        if(C[w[i]] == M)chk = 1, be = 1, ed = i;
    }
    for(i=mid+1;i<=n;i++){
        C[w[i]]++;
        C[w[i-mid]]--;
        if(C[w[i]] == M)chk = 1, be = i-mid+1, ed = i;
    }
    for(i=1;i<=n;i++)C[w[i]] = 0;
    if(chk)return true;
    return false;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        C[w[i]]++;
        if(C[w[i]] > M)M = C[w[i]];
    }
    for(i=1;i<=n;i++)C[w[i]]--;
    int b = 1, e = n, r, mid, bb, ee;
    while(b<=e){
        mid = (b+e)>>1;
        if(Pos(mid)){
            r = mid;
            bb = be, ee = ed;
            e = mid-1;
        }
        else b = mid+1;
    }
    printf("%d %d\n",bb,ee);
}