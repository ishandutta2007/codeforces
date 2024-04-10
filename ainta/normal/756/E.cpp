#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, A[301000],B[300100], L, Mod = 1000000007;
char p[10100];
vector<int>D[301000];
struct point{
    long long w[1500];
    int Div(int a){
        int i, x = 0;
        for(i=L-1;i>=1;i--){
            w[i-1] += w[i]%a * 1000000000;
            w[i]/=a;
            if(!x && w[i])x = i+1;
        }
        int ret = w[0]%a;
        w[0]/=a;
        if(w[0] && !x)x = 1;
        L = x;
        return ret;
    }
}M;
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        scanf("%d",&A[i]);
    }
    A[n+1] = 1e9;
    for(i=1;i<=n;i++){
        scanf("%d",&B[i]);
    }
    scanf("%s",p);
    for(i=0;p[i];i++);
    for(i=i-1;i>=0;i-=9){
        for(j=i-8;j<=i;j++){
            if(j<0)continue;
            M.w[L]=M.w[L]*10 + p[j]-'0';
        }
        L++;
    }
    D[1].push_back(1);
    for(i=1;i<=n;i++){
        int sz = D[i].size(), s = 0, rr, c = 0;
        if(A[i+1] != 1)rr = M.Div(A[i+1]);
        else rr = 0;
        for(j=0;j<sz+B[i];j++){
            if(j<sz)s = (s + D[i][j])%Mod;
            if(j>B[i])s = (s-D[i][j-B[i]-1]+Mod)%Mod;
            if(rr != j%A[i+1])continue;
            D[i+1].push_back(s);
        }
        if(!L)break;
    }
    printf("%d\n",L?0:D[i+1].empty()?0:D[i+1][0]);
}