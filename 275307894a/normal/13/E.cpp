#include<cstdio>
#include<cmath>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,a[200039],x,y,z,l[1039],r[1039],f[1039],ls[200039],rs[200039],ans,tot,now;
inline void read(int &x){
	x=0;char s=getchar();
	while(s<'0'||s>'9')s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(int x){
	if(x>9) print(x/10);
	putchar(x%10+48);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	register int i,j;
	read(n);
	read(m);
	k=sqrt(n);
	for(i=1;i<=n;i++) read(a[i]);
	for(i=n/k+1;i>=1;i--){
		if(i*k-k+1>n) continue;
		l[i]=i*k-k+1;r[i]=min(n,i*k);
		for(j=r[i];j>=l[i];j--){
			if(j+a[j]>r[i]) rs[j]=j+a[j],ls[j]=1;
			else rs[j]=rs[j+a[j]],ls[j]=ls[j+a[j]]+1;
		}
	}
	for(i=1;i<=m;i++){
		read(x);
		if(x){
			read(x);
			ans=x;tot=0;now=0;
			while(ans<=n){
			    tot+=ls[ans];now=ans;ans=rs[ans];
			}
			while(now<=n){
				if(now+a[now]>n) break;
				now+=a[now];
			}
			print(now);putchar(' ');print(tot);
			putchar('\n');
		}
		else{
			read(x);read(y);
			ans=(x-1)/k+1;
			a[x]=y;
			if(x+y>r[ans])ls[x]=1,rs[x]=x+y;
			else ls[x]=ls[x+y]+1,rs[x]=rs[x+y];
			for(j=x-1;j>=l[ans];j--){
				if(j+a[j]>r[ans]) ls[j]=1,rs[j]=j+a[j];
				else ls[j]=ls[j+a[j]]+1,rs[j]=rs[j+a[j]];
			}
		}
	}
	return 0;
}