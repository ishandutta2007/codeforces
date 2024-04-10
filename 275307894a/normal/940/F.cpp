#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int k,a[200039],f[200039],ans[200039],ch1[200039],ch2[200039],ch3[200039],st[200039],now[200039],nowhead,nows[200039];
struct yyy {
	int x,y,z,num;
} s[200039];
inline void read(int &x) {
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(int x) {
	if(x>9) print(x/10);
	putchar(x%10+48);
}
inline bool cmp(yyy x,yyy y) {
	if(x.x/k!=y.x/k) return x.x<y.x;
	if(x.y/k!=y.y/k) return (x.x/k&1)?x.y<y.y:x.y>y.y;
	return (x.y/k&1)?x.z<y.z:x.z>y.z;
}
int main() {
	register int i,l,r,mid,tot=0,tmp=0,head=0,n,m,x,y,_s,j;
	register yyy tmps;
	read(n);read(m);
	for(i=1; i<=n; i++) read(a[i]),now[++nowhead]=a[i];
	for(i=1; i<=m; i++) {
		read(_s);read(x);read(y);
		if(_s==2) ch1[++head]=x,ch2[head]=y,now[++nowhead]=y;
		else s[++tmp].x=x,s[tmp].y=y,s[tmp].z=head,s[tmp].num=tmp;
	}
	k=ceil(exp((log(n)+log(head))/3));
	sort(now+1,now+nowhead+1);
	sort(s+1,s+tmp+1,cmp);
	for(i=1; i<=nowhead; i++) {
		nows[i]=nows[i-1];
		if(now[i]!=now[i-1]) nows[i]++;
	}
	for(i=1; i<=n; i++) {
		l=0;r=nowhead+1;
		while(l+1<r) {
			mid=(l+r)>>1;
			if(a[i]>now[mid]) l=mid;
			else r=mid;
		}
		a[i]=nows[r];
	}
	for(i=1; i<=head; i++) {
		l=0;r=nowhead+1;
		while(l+1<r) {
			mid=(l+r)>>1;
			if(ch2[i]>now[mid]) l=mid;
			else r=mid;
		}
		ch2[i]=nows[r];
	}
	for(i=1; i<=head; i++) ch3[i]=a[ch1[i]],a[ch1[i]]=ch2[i];
	for(i=head; i>=1; i--) a[ch1[i]]=ch3[i];
	l=1;r=0;mid=0;st[0]=n*2;
	for(i=1; i<=tmp; i++) {
		tmps=s[i];
		//printf("%d %d %d %d\n",s[i].x,s[i].y,s[i].z,s[i].num);
		while(l>tmps.x) l--,st[f[a[l]]]--,f[a[l]]++,st[f[a[l]]]++;
		while(r<tmps.y) r++,st[f[a[r]]]--,f[a[r]]++,st[f[a[r]]]++;
		while(l<tmps.x) st[f[a[l]]]--,f[a[l]]--,st[f[a[l]]]++,l++;
		while(r>tmps.y) st[f[a[r]]]--,f[a[r]]--,st[f[a[r]]]++,r--;
		while(mid<tmps.z) {
			mid++,a[ch1[mid]]=ch2[mid];
			if(ch1[mid]>=l&&ch1[mid]<=r) {
				st[f[ch3[mid]]]--;f[ch3[mid]]--;st[f[ch3[mid]]]++;
				st[f[ch2[mid]]]--;f[ch2[mid]]++;st[f[ch2[mid]]]++;
			}
		}
		while(mid>tmps.z) {
			a[ch1[mid]]=ch3[mid];
			if(ch1[mid]>=l&&ch1[mid]<=r) {
				st[f[ch3[mid]]]--;f[ch3[mid]]++;st[f[ch3[mid]]]++;
				st[f[ch2[mid]]]--;f[ch2[mid]]--;st[f[ch2[mid]]]++;
			}
			mid--;
		}
		for(j=1; j<=n; j++) if(!st[j]) {ans[tmps.num]=j;break;}
	}
	for(i=1; i<=tmp; i++) print(ans[i]),putchar('\n');
}