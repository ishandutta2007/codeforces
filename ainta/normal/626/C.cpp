#include<stdio.h>
int n, m;
bool Pos(int K){
    int i, t;
    if(K/2<n || K/3<m)return false;
    if(K/2+K/3-K/6>=n+m)return true;
    return false;
}
int main(){
    int be = 0, ed = 10000000, mid, r;
    scanf("%d%d",&n,&m);
    while(be<=ed){
        mid = (be+ed)/2;
        if(Pos(mid)){
            r = mid;
            ed = mid - 1;
        }
        else be = mid + 1;
    }
    printf("%d\n",r);
}