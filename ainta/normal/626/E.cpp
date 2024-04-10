#include<stdio.h>
#include<algorithm>
using namespace std;
int w[201000], n, ck1, ck2;
long long s1, s2, s, A, B, S[201000];
long long Gap(int a, int x){
    return S[a]-S[a-x-1] + S[n]-S[n-x];
}
int main(){
    int i, be, ed, r, mid;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++)S[i]=S[i-1]+w[i];
    ck1 = 1, ck2 = 0;
    s = w[1];
    s1=0,s2=1;
    for(i=2;i<=n;i++){
        r = 1, be = 2, ed = min(n-i, i-1);
        while(be<=ed){
            mid = (be+ed)>>1;
            if(Gap(i,mid-1)*(2*mid+1) < Gap(i,mid)*(2*mid-1)){
                r = mid;
                be = mid+1;
            }
            else ed = mid - 1;
        }
        A = Gap(i,r)- (long long)(2*r+1)*w[i];
        B = 2*r+1;
        if(s1*B < A*s2){
            s1=A,s2=B,ck1=i,ck2=r;
        }
    }
    printf("%d\n",ck2*2+1);
    for(i=ck1-ck2;i<=ck1;i++)printf("%d ",w[i]);
    for(i=n-ck2+1;i<=n;i++)printf("%d ",w[i]);
}