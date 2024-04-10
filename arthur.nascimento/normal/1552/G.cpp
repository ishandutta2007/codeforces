#include <bits/stdc++.h>
#define maxn 42
#define mod 998244353
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define debug printf
using namespace std;

int n,K;

int qtd[maxn];
int vec[maxn][maxn];

int v[maxn];

int pos[maxn][maxn];
int val[maxn][maxn];
int old[maxn][maxn];

void go(int k){
    
   // debug("k %d - ",k); for(int i=0;i<n;i++) debug("%d ",v[i]); debug("\n");
    
    if(k == K){
        int q1 = (v[0] == 1);
        for(int i=1;i<n;i++)
            if(v[i] < v[i-1] || (q1 += v[i] == 1) == 2){
                printf("REJECTED\n");
                exit(0);
            }
        return;
    }
    
    int t = qtd[k];
    
    int q0 = 0, q1 = 0, q2 = 0;

    for(int i=0;i<t;i++){
        int a = vec[k][i];
        pos[k][i] = a;
        val[k][i] = v[a];
        if(v[a] == 0) q0++;
        if(v[a] == 1) q1++;
        if(v[a] == 2) q2++;
    }
    
    for(int i=0;i<q0;i++) val[k][i] = 0;
    for(int i=q0;i<q0+q1;i++) val[k][i] = 1;
    for(int i=q0+q1;i<t;i++) val[k][i] = 2;
    //sort(val[k], val[k]+t);
    
    vector<int> opt;
    
    for(int i=0;i<t;i++){
        old[k][pos[k][i]] = v[pos[k][i]];
        v[pos[k][i]] = val[k][i];
        if(val[k][i] == 1) v[pos[k][i]] = 2;
    }
 
    go(k+1);
    
    for(int i=q0;i<q0+q1;i++){
        v[pos[k][i]] = 0 ;
        go(k+1);
    }
    
    for(int i=0;i<t;i++){
        v[pos[k][i]] = old[k][pos[k][i]];
    }
    
}

main(){
    
    scanf("%d%d",&n,&K);
    
    for(int i=0;i<n;i++) v[i] = 1;
    
    for(int i=0;i<K;i++){
        scanf("%d",qtd+i);
        for(int j=0;j<qtd[i];j++)
            scanf("%d",&vec[i][j]), vec[i][j]--;
    }
    
    go(0);
    
    printf("ACCEPTED\n");
    
}