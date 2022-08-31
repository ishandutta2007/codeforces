#include<cstdio>
#include<algorithm>
using namespace std;
int w[20], n;
long long po[20];
long long Get(int a, int b){ // biggest : a, 2^b : 1
    if(a==0)return 0;
    if(4*n<=b)return 0;
    int i, j, pp = 1 << (b%4), ccc = 0, ck = 0;
    po[0] = 1;
    for(i=1;i<n;i++){
        po[i]=po[i-1] * (a+1);
    }
    for(i=0;i<=a;i++){
        if(i&pp)ccc++;
    }
    long long res = 0;
    for(i=n-1;i>=0;i--){
        int ppp = 0;
        if(i*4 <= b && b < (i+1)*4){
            ppp = 1 << (b-i*4);
            ck = 1;
        }
        for(j=0;j<=a;j++){
            if(j >= w[i])continue;
            if(ck==0){
                res += po[i-1] * ccc;
            }
            if(ck==1){
                if((j&ppp)!=ppp)continue;
            }
            if(ck){
                res += po[i];
            }
        }
        if(w[i] > a)break;
        if(ck == 1 && (w[i] & ppp)!=ppp)break;
        if(ck)ck = 2;
    }
    return res;
}
long long Calc(long long a){
    if(a < 1)a = 1;
    n = 0;
    while(a){
        w[n++] = a%16;
        a/=16;
    }
    long long s = 0;
    int i;
    for(i=1;i<=15;i++){
        s += Get(i, i) - Get(i-1, i);
    }
    return s;
}
int main(){
    int Q;
    long long L, R;
    scanf("%d",&Q);
    while(Q--){
        scanf("%llx%llx",&L,&R);
        printf("%lld\n",Calc(R+1) - Calc(L));
    }
}