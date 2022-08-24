#include<stdio.h>
#include<algorithm>
using namespace std;
long long n, Res;
void Do(int d1, int d2){
    long long be = (1ll<<d2), ed = (1ll << (d2+1)) - 1, ss, mid, t;
    int i;
    while(be<=ed){
        ss = 0;
        mid = (be+ed)/2;
        t = mid;
        for(i=0;i<=d2-d1;i++){
            ss += t;
            t/=2;
        }
        if(ss == n){
            Res++;
            return;
        }
        if(ss < n)be = mid + 1;
        else ed = mid - 1;
    }
}
long long GetMin(long long a, int d){
    if(d==0)return a;
    return GetMin(a*2,d-1)+a;
}
long long GetMax(long long a, int d){
    if(d==0)return a;
    return GetMax(a*2+1,d-1)+a;
}
int C[100], a1, a2;
long long S[100], D[21][21][10000];
long long Calc(int d, long long g){
    if(d==0){
        if(!g)return 1;
        return 0;
    }
    if(S[d] < g)return 0;
    if(d<=20 && g<10000){
        if(D[min(a1,d)][min(a2,d)][g]!=-1)return D[min(a1,d)][min(a2,d)][g];
    }
    long long s = Calc(d-1,g);
    long long t = (1ll << d) - 1;
    if(C[d]>=1 && g>=t)s += Calc(d-1,g-t) * C[d];
    if(C[d]>=2 && g>=t*2)s += Calc(d-1,g-t*2);
    if(d<=20 && g<10000) D[min(a1,d)][min(a2,d)][g] = s;
    return s;
}
void Pro(long long g, int d1, int d2){
    int i;
    for(i=0;i<=50;i++)C[i]=0;
    for(i=1;i<=d1;i++)C[i]++;
    for(i=1;i<=d2;i++)C[i]++;
    a1 = min(d1,d2);
    a2 = max(d1,d2);
    for(i=1;i<=50;i++){
        S[i] = S[i-1] + ((1ll << i) - 1) * C[i];
    }
    Res += Calc(max(d1,d2), g);
}
void Do3(int d1, int d2, int d3){
    long long be = (1ll<<d1), ed = (1ll << (d1+1))-1, mid, M1, M2, r = -1, ss1 = 0, ss2 = 0, t;
    while(be<=ed){
        mid = (be+ed)/2;
        M1 = GetMin(mid*2,d2-d1-1) + GetMin(mid*2+1,d3-d1-1) + mid;
        M2 = GetMax(mid*2,d2-d1-1) + GetMax(mid*2+1,d3-d1-1) + mid;
        if(M1 <= n && n <= M2){
            r = mid;
            break;
        }
        if(n < M1)ed = mid - 1;
        else be = mid + 1;
    }
    if(r==-1)return;
    ss1 = 0, t = 1;
    int i;
    for(i=0;i<d2-d1;i++){
        ss1 += t;
        t*=2;
    }
    t=1;
    for(i=0;i<d3-d1;i++){
        ss2 += t;
        t*=2;
    }
    Pro(n - r - (r*2) *ss1 - (r*2+1) * ss2, d2-d1-1, d3-d1-1);
}
int main(){
    int i, j, k;
    for(i=0;i<21;i++)for(j=0;j<21;j++)for(k=0;k<10000;k++)D[i][j][k]=-1;
    scanf("%lld",&n);
    for(i=0;i<50;i++){
        for(j=i;j<50;j++){
            Do(i,j);
        }
    }
    for(i=0;i<50;i++){
        for(j=i+1;j<50;j++){
            for(k=i+1;k<50;k++){
                Do3(i,j,k);
            }
        }
    }
    printf("%lld\n",Res);
}