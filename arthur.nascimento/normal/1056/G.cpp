#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug 
#define maxn 100100
#define lg 500

int X[lg*maxn];
int sz[lg*maxn];
int L[lg*maxn];
int R[lg*maxn];

int qtd = 1;

inline void copy(int a,int b){
    X[b] = X[a];
    sz[b] = sz[a];
    L[b] = L[a];
    R[b] = R[a];
}

inline int top(int a,int b){
    return (rand()%(a+b)) < a;
}

void calc(int u){
    sz[u] = sz[L[u]] + sz[R[u]] + 1;
}

int merge(int l,int r){
    
    if(l == 0){
        return r;
    }
    if(r == 0){
        return l;
    }
    
    if(top(sz[l], sz[r])){
        
        int rc = merge(R[l],r);
        copy(l,qtd);
        R[qtd] = rc;
        calc(qtd);
        return qtd++;
        
    }
    else {
        
        int lc = merge(l,L[r]);
        copy(r,qtd);
        L[qtd] = lc;
        calc(qtd);
        return qtd++;
        
    }
    
}

void split(int u,int s,int &l,int &r){
    
    if(u == 0){
        l = r = 0;
        return;
    }
    
    if(sz[L[u]] >= s){
        
        split(L[u],s,l,r);
        copy(u,qtd);
        L[qtd] = r;
        r = qtd;
        calc(qtd);
        qtd++;
        
    }
    
    else {
        
        split(R[u],s-sz[L[u]]-1,l,r);
        copy(u,qtd);
        R[qtd] = l;
        l = qtd;
        calc(qtd);
        qtd++;
        
    }

}

int n,m,s;
ll t;

int get(int u,int l,int r){
    
    if(l < 0) l += n, r += n;
    
    int x,y,w,z;
    
    split(u,l,x,y);
    split(y,r-l+1,w,z);
    
    return w;

}

void print(int u){
    if(u == 0) return;
    print(L[u]);
    debug("%d ",X[u]);
    print(R[u]);
}

int XX[maxn];
int LL[maxn];
int RR[maxn];
int ssz[maxn];

int clean(int u){
    
    if(u == 0) return 0;
   
    int id = qtd++;
    XX[id] = X[u];
    ssz[id] = sz[u];
    LL[id] = clean(L[u]);
    RR[id] = clean(R[u]);
    return id;
    
}


int jmp[60][maxn];

int main(){
 
    scanf("%d%d%d%lld",&n,&m,&s,&t);
    s--;
    
    while(t%n){
        if(s < m) s = (s+t)%n;
        else s = (s-(t%n)+n)%n;
        t--;
    }
  
    int qm = 0;
    
    int r = 0;
    
    for(int i=0;i<n;i++){
        X[qtd] = i;
        sz[qtd] = 1;
        qtd++;
        r = merge(r,qtd-1);
    }
    
    //print(r);debug("\n");
    
    for(int i=1;i<=n-1;i++){
        int dupli = merge(r,r);
        int A = get(dupli,i,m+i-1);  
        int B = get(dupli,m-i,n-1-i);
        
      //  print(A);printf("\n");
    //    print(B);printf("\n");
        
        r = merge(A,B);
      //  print(r);debug("\n");
    
        qm = max(qm,qtd);
        
        if(qtd > lg*maxn-20*lg){
            qtd = 1;
            r = clean(r);
            for(int j=1;j<qtd;j++){
                R[j] = RR[j];
                L[j] = LL[j];
                X[j] = XX[j];
                sz[j] = ssz[j];
            }
        }
        
    }
    
    for(int i=0;i<n;i++){
        jmp[0][i] = X[get(r,i,i)];
    }
    
    for(int i=1;i<60;i++)
        for(int j=0;j<n;j++)
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    
    qm = max(qm,qtd);
    debug("%d\n",qm);
    t/=n;
    
    for(int i=0;i<60;i++)
        if(t & (1ll<<i))
            s = jmp[i][s];
    
    printf("%d\n",s+1);
}

/*
0 1 2 
1

*/