#include<stdio.h>
#include<algorithm>
#include<math.h>
#define pli pair<long long,int>
using namespace std;
int D[1010000], res, T[1010000], P[1010000];
long long m;
pli Get(long long m){
    if(m<=1000000){
        return pli(P[m],T[m]);
    }
    double tt = pow((double)m,1.0/3);
    long long K = (long long)(tt+0.5);
    while(K*K*K>m) K--;
    pli t1 = Get(m-K*K*K);
    pli t2 = Get(3*K*K - 3*K);
    if(t1.second >= t2.second){
        return pli(K*K*K + t1.first, t1.second + 1);
    }
    return pli((K-1)*(K-1)*(K-1) + t2.first, t2.second + 1);
}
int main(){
    int i, pv = 1;
    for(i=1;i<=1000000;i++){
        while(i>=(pv+1)*(pv+1)*(pv+1))pv++;
        D[i] = 1 + D[i-pv*pv*pv];
    }
    scanf("%lld",&m);
    for(i=1;i<=1000000;i++){
        T[i] = max(D[i],T[i-1]);
        if(T[i]==D[i])P[i]=i;
        else P[i] = P[i-1];
    }
    pli tp = Get(m);
    printf("%d %lld\n",tp.second,tp.first);
}