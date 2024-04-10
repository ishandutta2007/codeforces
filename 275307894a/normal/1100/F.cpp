#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,x,y,z,a[500039],flag[500039],ans,pus,mid;
struct yyy{int x,y,l,r,ans;}s[500039];
struct base{
	int s[39];
	inline void get(int x){
		for(int i=19;~i;i--){
			if(x&(1<<i)){
				if(!s[i]){s[i]=x;break;}
				x^=s[i];
			}
		}
	}
	inline void clear(){memset(s,0,sizeof(s));}
}f[500039],tmp;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=1;i<=m;i++) scanf("%d%d",&s[i].x,&s[i].y),s[i].l=1,s[i].r=n,s[i].ans=-1;;
	while(1){
		for(i=1;i<=n;i++) if(flag[i]) flag[i]=0,f[i].clear();
		for(i=1;i<=m;i++){
			if(~s[i].ans) continue;
			mid=s[i].l+s[i].r>>1;
			if(!flag[mid]){
				flag[mid]=1;f[mid].get(a[mid]);
				for(j=mid-1;j>=s[i].l;j--) flag[j]=1,f[j]=f[j+1],f[j].get(a[j]);
				if(mid+1<=s[i].r){
					f[mid+1].get(a[mid+1]);
					for(j=mid+2;j<=s[i].r;j++) flag[j]=1,f[j]=f[j-1],f[j].get(a[j]);
				}
			}
		}pus=0;
		for(i=1;i<=m;i++){
			if(~s[i].ans) continue;
			mid=s[i].l+s[i].r>>1;pus=1;
			if(s[i].l==s[i].r){s[i].ans=a[mid];continue;}
			if(s[i].y<=mid)s[i].r=mid;
			else if(s[i].x>mid) s[i].l=mid+1;
			else{
				tmp=f[s[i].x];ans=0;
				for(j=19;~j;j--)tmp.get(f[s[i].y].s[j]); 
				for(j=19;~j;j--)if((ans^tmp.s[j])>ans) ans^=tmp.s[j];
				s[i].ans=ans;
			} 
		}
		if(!pus) break;
	}
	for(i=1;i<=m;i++) printf("%d\n",s[i].ans);
}