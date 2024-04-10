#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define debug 
#define mk make_pair
#define pii pair<int,int>
#define mod 1000000007 
using namespace std;

int mn[maxn];
int mx[maxn];

int last[maxn];

int T[3*maxn];

void upd(int idx,int val){
    idx++;
    while(idx < 3*maxn){
        T[idx] += val;
        idx += idx&-idx;
    }
}

int qry(int idx){
    int r = 0;
    idx++;
    while(idx){
        r += T[idx];
        idx -= idx&-idx;
    }
    return r;
    
}

int get(int a,int b){
    return qry(b) - qry(a-1);
}

main(){
    
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<n;i++)
        mn[i] = mx[i] = i;
        
    int t=0;
    for(int i=n-1;i>=0;i--,t++){
        upd(t,1);
        last[i] = t; 
    }
    
    for(int i=0;i<m+n;i++){
        
        int a;
        if(i < m) scanf("%d",&a), a--;
        else a = i - m;
        if(i < m) mn[a] = 0;
        mx[a] = max(mx[a],get(last[a]+1,t-1));
        if(i < m) upd(last[a],-1);
        if(i < m) last[a] = t;
        if(i < m) upd(last[a],1);
        t++;
        
    }
    
    for(int i=0;i<n;i++)
        printf("%d %d\n",1+mn[i],1+mx[i]);
    
}