#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define eps 1e-8
#define PB push_back
#define MP make_pair
using namespace std;
double pi=asin(1.0)*2;

long long ans[200];
long long g[200][200],h[200][200];
int t[200];
int n,m;

bool test(int i,long long t){
    if (t<=0||t>1000000) return false;
    if (ans[i]!=-1){
        if (ans[i]>-1&&ans[i]!=t) return false;
        if (ans[i]<-1&&ans[i]!=-t-1) return false;
        return true;
    }
    ans[i]=-t-1;
    for (int z=0;z<n;z++) if (g[i][z]!=-1){
        if (g[i][z]*h[i][z]%t!=0) return false;
        long long tt=g[i][z]*h[i][z]/t;
        if (__gcd(tt,t)!=g[i][z]) return false;
        if (t*tt/__gcd(tt,t)!=h[i][z]) return false;
        if (!test(z,tt)) return false;
    }
    return true;
}

bool getans(int i){
    if (t[i]==0){
        ans[i]=1;
        return true;
    }
    int k=-1;
    for (int j=0;j<n;j++) if (g[i][j]!=-1){
        if (k==-1) k=j;
        if (h[i][j]/g[i][j]<h[i][k]/g[i][k]) k=j;
    }
    for (long long z=1;z<=h[i][k]/g[i][k];z++){
        if (test(i,z*g[i][k])){
            for (int tt=0;tt<n;tt++) if (ans[tt]<-1) ans[tt]=-ans[tt]-1;
            return true;
        }
        for (int tt=0;tt<n;tt++) if (ans[tt]<0) ans[tt]=-1;
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(g,-1,sizeof(g));
    memset(t,0,sizeof(t));
    bool ok=true;
    for (int i=0;i<m;i++){
        int k,l,o,p;
        scanf("%d%d%d%d",&k,&l,&o,&p);
        k--;l--;
        g[k][l]=g[l][k]=o;
        h[k][l]=h[l][k]=p;
        t[k]++;t[l]++;
        if (p%o!=0) ok=false;
    }
    memset(ans,-1,sizeof(ans));
    if (ok) for (int i=0;i<n;i++) if (ans[i]==-1) if (!getans(i)){
        ok=false;
        break;
    }
    if (!ok) printf("NO\n");
    else {
        printf("YES\n");
        for (int i=0;i<n;i++){
            if (i) printf(" ");
            printf("%d",(int)ans[i]);
        }
        printf("\n");
    }
    
    return 0;
}