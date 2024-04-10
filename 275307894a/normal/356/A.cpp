#include<cstdio>
int n,m,sx[300039],sy[300039],sz[300039],x,y,z,f[1800039],s[1800039];
inline void read(int &x) {
	x=0;char s=getchar();int fs=1;
	while(s<'0'||s>'9'){if(s=='-')fs=-1;s=getchar();}
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
	x*=fs;
}
inline void print(int x){
	if(x<0){putchar('-');print(-x);return;}
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
inline void push(int l,int r,int now){
	int m=(l+r)>>1;
	f[now<<1]=f[now];
	s[now<<1]=f[now]*(m-l+1);
	f[now<<1|1]=f[now];
	s[now<<1|1]=f[now]*(r-m);
	f[now]=0;
}
inline void get(int l, int r,int now){
	if(x<=l&&r<=y){
		f[now]=z;
		s[now]=z*(r-l+1);
		return;
	}
	int m=(l+r)>>1;
	if(f[now])push(l,r,now);
	if(x<=m) get(l,m,now<<1);
	if(y>m) get(m+1,r,now<<1|1);
	s[now]=s[now<<1]+s[now<<1|1];
	return;
}
inline int  find(int l,int r,int now){
	if(x<=l&&r<=y)return s[now];
	int m=(l+r)>>1,fs=0;
	if(f[now])push(l,r,now);
	if(x<=m) fs+=find(l,m,now<<1);
	if(y>m) fs+=find(m+1,r,now<<1|1);
	return fs;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	read(n);read(m);
	for(i=1;i<=m;i++)read(sx[i]),read(sy[i]),read(sz[i]);
	for(i=m;i>=1;i--){
		x=sx[i];y=sz[i]-1;z=sz[i];
		if(x<=y)get(1,n,1);
		x=sz[i]+1;y=sy[i];
		if(x<=y)get(1,n,1);
	}
	for(i=1;i<=n;i++) x=y=i,print(find(1,n,1)),putchar(' ');
	return 0;
}