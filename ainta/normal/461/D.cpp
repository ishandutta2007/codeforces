#include<stdio.h>
#include<algorithm>
using namespace std;
int n, Q, UF[101000], D[101000], tdep, chk;
int Find(int a){
    if(a == UF[a])return a;
    int td = tdep;
    tdep ^= D[a];
    UF[a] = Find(UF[a]);
    D[a] = tdep ^ td;
    return UF[a];
}
void Do(int a, int b, char ch){
    int d1, d2;
    tdep = 0;
    a = Find(a);
    d1 = tdep;
    tdep = 0;
    b = Find(b);
    d2 = tdep;
    if(a == b){
        if(ch == 'o'){
            if(d1 == d2)chk = 1;
            return;
        }
        else{
            if(d1 != d2)chk = 1;
            return;
        }
    }
    if(ch == 'o'){
        UF[a] = b;
        D[a] = d1^d2^1;
    }
    else{
        UF[a] = b;
        D[a] = d1^d2;
    }
}
bool v[101000];
int main()
{
    int x, y, i, L, R, Res = 0;
    long long Ans = 1, Mod = 1000000007;
    char p[2];
    scanf("%d%d",&n,&Q);
    for(i=0;i<=n;i++)UF[i]=i;
    while(Q--){
        scanf("%d%d%s",&x,&y,p);
        L = y - (x-1);
        if(L < 1) L = 2 - L;
        R = y + (x-1);
        if(R > n) R = 2*n - R;
        if(L <= 2){
            Do(0, R, p[0]);
        }
        else{
            Do(L-2, R, p[0]);
        }
    }
    if(chk){
        printf("0\n");
        return 0;
    }
    for(i=0;i<=n;i++){
        x = Find(i);
        if(!v[x]){
            v[x] = true;
            Res++;
        }
    }
    Res--;
    for(i=0;i<Res;i++){
        Ans=Ans*2%Mod;
    }
    printf("%lld\n",Ans);
}