#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 262144
using namespace std;
int n, K, m, w[101000];
vector<int>A,B;
long long IT[SZ+SZ];
long long Max(int b, int e){
    b+=SZ,e+=SZ;
    long long r=0;
    while(b<=e){
        r=max(IT[b],IT[e]);
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return r;
}
void Put(int a, long long x){
    a+=SZ;
    while(a){
        IT[a]=max(IT[a],x);
        a>>=1;
    }
}
long long SA[101000], SB[101000];
int main(){
    int i;
    scanf("%d%d%d",&n,&K,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(w[i]<=m)A.push_back(w[i]);
        else B.push_back(w[i]);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(i=0;i<A.size();i++)SA[i+1]=SA[i]+A[i];
    for(i=0;i<B.size();i++)SB[i+1]=SB[i]+B[i];
    long long res=0;
    for(i=0;i<=B.size();i++){
        long long t = n;
        if(i)t -= 1ll*K*(i-1);
        if(t<i)continue;
        int z = t-i;
        if(z>A.size())z=A.size();
        res=max(res,SB[i] + SA[z]);
    }
    printf("%lld\n",res);
}