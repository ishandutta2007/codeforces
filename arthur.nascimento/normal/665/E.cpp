#include <bits/stdc++.h>
#define maxn 1001000
#define debug 
typedef long long ll;
using namespace std;

struct node {
    int kid[2];
    int qtd;
};

node T[31*maxn];
int cnt = 1;

int v[maxn];

void add(int cur,int val,int pos){
    if(pos == -1){
        T[cur].qtd++;
        return;
    }
    int b = (val & (1<<pos));
    b = (b != 0);
    if(T[cur].kid[b] == 0)
        T[cur].kid[b] = cnt++;
    add(T[cur].kid[b],val,pos-1);
    T[cur].qtd++;
}

int get(int cur,int x,int k,int pos){
    if((x>>(pos+1)) > (k>>(pos+1)))
        return T[cur].qtd;
    if((x>>(pos+1)) < (k>>(pos+1)))
        return 0;
    if(pos == -1)
        return T[cur].qtd;
    int r = 0;
    if(T[cur].kid[0])
        r += get(T[cur].kid[0],x,k,pos-1);
    if(T[cur].kid[1])
        r += get(T[cur].kid[1],x^(1<<pos),k,pos-1);
    return r;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
    int x = 0;
    ll ans = 0;
    for(int i=0;i<n;i++){
        add(0,x,30);
        x ^= v[i];
        int u = get(0,x,k,30);
        debug("i %d + %d\n",i,u);
        ans += u;
    }
    printf("%lld\n",ans);
}