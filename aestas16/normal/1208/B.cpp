#include <cstdio>
#include <cstring>
 
template<class T>void fr(T &a) {
	T s=0,w=1;a=0;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	a=w*s;
}
template<class T>T in() {T a;fr(a);return a;}
#define R() in<int>()
 
template<class T,class X>struct num_hash {
    #define KEY unsigned long long
    KEY mod;
    int tot,adj[100010],nxt[100010];
    struct node {T key;X num;}f[100010];
    void clear() {
    	tot=0;
    	memset(adj,0,sizeof(adj));
    	memset(f,0,sizeof(f));
    	mod=100003;
    }
    KEY Hash(T a) {return a%mod;}
    void push(T key,X num) {
        KEY h=Hash(key);
        for(int e=adj[h];e;e=nxt[e])
            if(f[e].key==key)return ;
        nxt[++tot]=adj[h];adj[h]=tot;
        f[tot]=(node){key,num};
    }
    X get(T key) {
        KEY h=Hash(key);
        for(int e=adj[h];e;e=nxt[e])
            if(f[e].key==key)return f[e].num;
        return 0;
    }
};
num_hash<int,int>h;
int n,a[2010];
 
bool check(int x) {
	for(int i=1;i<=n-x+1;i++) {
		h.clear();
		int l=i,r=i+x-1,f=1;
		for(int j=1;j<=n;j++) {
			if(j>=l&&j<=r)continue;
			if(h.get(a[j])) {f=0;break;}
			h.push(a[j],1);
		}
		if(f)return true;
	}
	return false;
}
 
int main() {
	fr(n);int l=0,r=n;
	for(int i=1;i<=n;i++) fr(a[i]);
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	return !printf("%d\n",l);
}