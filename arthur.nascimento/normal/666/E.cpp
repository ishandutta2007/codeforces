#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;
#define debug 
#define maxn 2*600600
#define pii pair<int,int>
#define INF (1<<30)
#define lg 24
#define N 100100
 
pii T[4*N];
 
pii qry(int ini,int fim,int p,int l,int r){
    if(l > fim || r < ini) return pii(-1,-1);
    if(ini >= l && fim <= r) return T[p];
    int mid = (ini+fim)/2;
    pii ret = max ( qry(ini,mid,2*p,l,r), qry(mid+1,fim,2*p+1,l,r));
    return ret;
}
 
void upd(int ini,int fim,int p,int pos){
    if(pos > fim || pos < ini) return;
    if(ini == fim) {
        T[p].first++;
        return;
    }
    int mid = (ini+fim)/2;
    upd(ini,mid,2*p,pos);
    upd(mid+1,fim,2*p+1,pos);
    T[p] = max(T[2*p],T[2*p+1]);
}
 
void zera(int ini,int fim,int p){
    if(T[p].first == 0) return;
    if(ini == fim){
        T[p].first = 0;
        return;
    }
    int mid = (ini+fim)/2;
    zera(ini,mid,2*p);
    zera(mid+1,fim,2*p+1);
    T[p] = pii(0,-ini);
}
 
void init(int ini,int fim,int p){
    if(ini == fim){
        T[p].first = 0;
        T[p].second = -ini;
        return;
    }
    int mid = (ini+fim)/2;
    init(ini,mid,2*p);
    init(mid+1,fim,2*p+1);
    T[p].first = 0;
    T[p].second = -ini;
}
 
char s[maxn];
int id[maxn];
pii ans[maxn];
 
struct query {
    int id, l, r;
    query(int id=0,int l=0,int r=0): id(id), l(l), r(r) {}
};
 
struct SuffixTree {
	char s[maxn];
//	map<int,int> to[MAXN];
    ll mask[maxn];
    int leaf[maxn];
    int sub[maxn];
    int heavy[maxn];
    int to[30][maxn];
    int lca[lg][maxn];
    int jmp[lg][maxn];
	int len[maxn]={INF},fpos[maxn],link[maxn];
	int node,pos,sz=1,n=0;
	vector<query> Q[maxn];
	void clear(){
		node=pos=n=0;
		ll u;
		fore(i,0,sz){
		    while(mask[i]){
		        u = mask[i]&-mask[i];
		        to[ __builtin_ctzll(u) ][i] = 0;
		        mask[i] -= u;
		    }
		   // to[64][i] = 0;
		}
		sz=1;
	}
	int make_node(int p, int l){ //printf("len[%d] = %d\n",sz,l);
		fpos[sz]=p;len[sz]=l;return sz++;}
	void go_edge(){
		while(pos>len[to[s[n-pos]][node]]){
			node=to[s[n-pos]][node];
			pos-=len[node];
		}
	}
	void add(int c){
		s[n++]=c;pos++;
		int last=0;
		while(pos>0){
			go_edge();
			int edge=s[n-pos];
			int& v=to[edge][node];
			mask[node] |= (1ll<<edge);
			int t=s[fpos[v]+pos-1];
			if(v==0){//printf("ha\n");
				v=make_node(n-pos,INF);
				link[last]=node;last=0;
			}
			else if(t==c){link[last]=node;return;}
			else {
				int u=make_node(fpos[v],pos-1);
				to[c][u]=make_node(n-1,INF);
				to[t][u]=v;
				mask[u] |= (1ll<<c);
				mask[u] |= (1ll<<t);
				fpos[v]+=pos-1;len[v]-=pos-1;
				v=u;link[last]=u;last=u;
			}
			if(node==0)pos--;
			else node=link[node];
		}
	}
	ll doit(){
		ll r=0;
		fore(i,1,sz)
		    if(len[i] < 1e6)
		        r += len[i];
	
		return r;
	}
	ll go(int vx,int sz=0,int pode=1,int p=0){ 
	    
	    sub[vx] = 1;
		if(vx) sz += min(len[vx], n-fpos[vx]);
 
		int are = min(len[vx], n-fpos[vx]);
		if(vx == 0) are = 0;
		
    	lca[0][vx] = p;
		jmp[0][vx] = are;
		
		for(int i=1;i<lg;i++){
		    lca[i][vx] = lca[i-1][lca[i-1][vx]];
		    jmp[i][vx] = jmp[i-1][vx] + jmp[i-1][lca[i-1][vx]];
		}
		
		if(len[vx] > 1e6 && vx && sz > 1)
	        leaf[n-sz] = vx;
			
		debug("oi vx %d len %d fpos %d sz %d pode %d\n",vx,len[vx],fpos[vx],sz,pode);
 
	    ll mm = mask[vx], u = 0;
	    heavy[vx] = -1;
	    int shv = -1;
        while(mm){
            u = mm&-mm;
            int kid = to[__builtin_ctzll(u)][vx];
            debug("%d -> %d\n",vx,kid);
			go(kid,sz,1,vx);
			sub[vx] += sub[kid];
			if(heavy[vx] == -1 || sub[kid] > shv)
			    heavy[vx] = kid, shv = sub[kid];
			mm -= u;
		}
		return 0;
	}
	
	void go2(int vx,int sz=0,int pode=1,int p=0){
	    debug("go2 %d\n",vx);
		if(vx) sz += min(len[vx], n-fpos[vx]);
		debug("oi vx %d len %d fpos %d sz %d pode %d\n",vx,len[vx],fpos[vx],sz,pode);
 
	    ll mm = mask[vx], u = 0;
        while(mm){
            u = mm&-mm;
            int kid = to[__builtin_ctzll(u)][vx];
            if(kid != heavy[vx])
			    go2(kid,sz,1,vx);
			zera(0,N-1,1);
            debug("zera\n");
			mm -= u;
		}
 
		if(heavy[vx]+1) go2(heavy[vx],sz,1,vx);
 
		mm = mask[vx], u = 0;
        while(mm){
            u = mm&-mm;
            int kid = to[__builtin_ctzll(u)][vx];
            if(kid != heavy[vx]) 
		    	go3(kid,sz,1,vx);
 
			mm -= u;
		}
		if(len[vx] > 1e6 && vx && sz > 1)
		    if(id[n-sz]+1)
    	        upd(0,N-1,1,id[n-sz]);//printf("add %d\n",id[n-sz]);   
		
		for(int i=0;i<Q[vx].size();i++){
		   // printf("ask %d\n",Q[vx][i].id);   
		    ans[Q[vx][i].id] = qry(0,N-1,1,Q[vx][i].l,Q[vx][i].r);
		}
	
	}
	
	void go3(int vx,int sz=0,int pode=1,int p=0){ 
	    
	    if(vx) sz += min(len[vx], n-fpos[vx]);
		if(len[vx] > 1e6 && vx && sz > 1)
		    if(id[n-sz]+1){
		        upd(0,N-1,1,id[n-sz]);
		        debug("add %d\n",id[n-sz]);   
		    }
		
	    ll mm = mask[vx], u = 0;
        while(mm){
            u = mm&-mm;
            int kid = to[__builtin_ctzll(u)][vx];
			go3(kid,sz,1,vx);
			mm -= u;
		}
	}
	
	
};
 
SuffixTree t;
 
int main(){
    init(0,N-1,1);
    memset(id,-1,sizeof(id));
    scanf(" %s",s);
   //for(int i=0;i<500000;i++) s[i] = 'a';
   //s[500000] = 0;
    int len = strlen(s);
    for(int i=0;i<len;i++)
        t.add(s[i]-'a'+1);
    t.add(27);
    
    int pos = len+1;
    int n, trash = 2;
    scanf("%d",&n);getchar();
    for(int i=0;i<n;i++){
        char ch;
        while((ch=getchar()) >= 'a'){
            t.add(ch-'a'+1);
            id[pos] = i;
            pos++;
            trash++;
        }
        t.add(27);
        pos++;
        trash++;
    }
    
    t.add(0);
    t.go(0);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int l,r,sl,sr;
        scanf("%d%d%d%d",&l,&r,&sl,&sr);
        l--, r--, sl--, sr--;
        int node = t.leaf[sl];
        int skip = len - sr - 1 + trash;
        debug("node = %d skip %d\n",node,skip);
        for(int j=lg-1;j>=0;j--)
            if(t.jmp[j][node] <= skip){
                skip -= t.jmp[j][node];
                debug("->%d jmp %d\n",t.lca[j][node],t.jmp[j][node]);
                node = t.lca[j][node];
            }
        debug("+ %d\n",node);
        t.Q[node].pb(query(i,l,r));
    }
    
    t.go2(0);
    
    for(int i=0;i<q;i++)
        printf("%d %d\n",1-ans[i].second,ans[i].first);
}