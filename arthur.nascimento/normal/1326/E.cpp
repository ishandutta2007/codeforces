#include <bits/stdc++.h>
#define maxn 600600
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...)// fprintf(stderr,args)
using namespace std;

int T[4*maxn];
int sum[4*maxn];
int suf[4*maxn];

void upd(int ini,int fim,int p,int pos,int val){ ;
    if(pos < ini || pos > fim) return;
    if(ini == fim){
        T[p] = sum[p] = suf[p] = val;
        return;
    }
    int mid = (ini+fim)/2;
    upd(ini,mid,2*p,pos,val);
    upd(mid+1,fim,2*p+1,pos,val);
    sum[p] = sum[2*p] + sum[2*p+1];
    suf[p] = max(suf[2*p+1], suf[2*p] + sum[2*p+1]);
}

int p[maxn];
int q[maxn];
int pos[maxn];

main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",p+i);
        pos[p[i]] = i+1;  
    }
    for(int i=0;i<n;i++)
        scanf("%d",q+i);
    
    int nxt = n;
    for(int i=0;i<n;i++){
        
        while(suf[1] <= 0){
            debug("+ el %d\n",pos[nxt]);
            upd(0,2*n+2,1,2*pos[nxt],1);
            nxt--;
        }
        
        printf("%d\n",nxt+1);
        
        debug("+ bomb %d\n",q[i]);
        upd(0,2*n+2,1,2*q[i]+1,-1);        
    }
    
    
}