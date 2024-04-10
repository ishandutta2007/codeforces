#include<bits/stdc++.h>
#define int long long
#define N 500015
using namespace std;
int n,a[N],b[N],c[N],d[N],pre[N],suf[N],ans,pos,f[N][30],Log[N];
void get_log(){
    Log[1] = 0;
    for(int i = 2; i<=n+1; i++){
        Log[i] = Log[i/2]+1;
    }
}
int Min(int a,int b){
	return a<b?a:b;
}
void RMQ(){
    for(int i = 1; i<=n; i++){
        f[i][0] = a[i];
    }
    for(int j = 1; (1<<j)<=n; j++){
        for(int i = 1; i+(1<<(j-1))<=n; i++){
            f[i][j] = Min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
 
        }
    }
}
int get_min(int l,int r){
    int k = Log[r-l+1];
    return min(f[l][k],f[r-(1<<k)+1][k]);
}
int get1(int u){
	int l = 1,r = u-1,mid,cur = a[u];
	while(l+3<=r){
		mid = (l+r)/2;
		int m1,m2;
		m1 = get_min(l,mid);
		m2 = get_min(mid+1,r); 
		if(m2 < cur){
			l = mid;
		}else{
			if(m1 < cur) r = mid;
			else return 0;
		}
	}
	for(int i = r;i >= l;--i)
		if(a[i] < cur) return i;
	return 0;
}
int get2(int u){
	int l = u+1,r = n,mid,cur = a[u];
	while(l+3<=r){
		mid = (l+r)/2;
		int m1,m2;
		m1 = get_min(l,mid);
		m2 = get_min(mid+1,r); 
		if(m1 < cur){
			r = mid;
		}else{
			if(m2 < cur) l = mid;
			else return n+1;
		}
	}
	for(int i = l;i <= r;++i)
		if(a[i] < cur) return i;
	return n+1;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;++i) scanf("%lld",&a[i]);
	get_log();
	RMQ();
	for(int i = 1;i <= n;++i) c[i] = get1(i);
	for(int i = 1;i <= n;++i) d[i] = get2(i);
	pre[0] = 0;
	for(int i = 1;i <= n;++i){
		int las = c[i];
		pre[i] = pre[las]+(i-las)*a[i];
	}
	suf[n+1] = 0;
	for(int i = n;i > 0;--i){
		int las = d[i];
		suf[i] = suf[las]+(las-i)*a[i];
	}
	for(int i = 0;i <= n;++i){
		int res = pre[i]+suf[i+1];
		if(res > ans) ans = res,pos = i;
	}
	int minn = 0x3f3f3f3f3f3f3f3f;
	for(int i = pos;i > 0;--i){
		if(a[i] < minn){
			b[i] = a[i];
			minn = a[i];
		}else{
			b[i] = minn;
		}
	}
	minn = 0x3f3f3f3f3f3f3f3f;
	for(int i = pos+1;i <= n;++i){
		if(a[i] < minn){
			b[i] = a[i];
			minn = a[i];
		}else{
			b[i] = minn;
		}
	}
	for(int i = 1;i <= n;++i){
		printf("%lld ",b[i]);
	}
	return 0;
}
/*
7
1 5 3 7 4 2 3
*/