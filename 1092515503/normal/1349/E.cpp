#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200100],b[200100];
void pr(){for(int i=1;i<=n;i++)printf("%lld",b[n-i+1]);puts("");}
void mina(){
	ll t=1;
	for(int i=n;;i--){
		int j=i;
		while(j&&!a[j])j--;
		if(!j){for(int k=1;k<=i;k++)b[k]=t;break;}
		b[j]=t+j-1;
		for(int k=j+1;k<=i;k++)b[k]=t+j;
		t+=j,i=j;
	}
	pr();
}
bool check(int l,int r,ll val){
//	printf("CHECK:[%d,%d,%lld]\n",l,r,val);
	if(val==0)return true;
	if(val<0||(1ll*(r+l)*(r-l+1)>>1)<val)return false;
	int u=l-1,v=r;
	while(u<v){
		int w=(u+v+1)>>1;
		if(val>=(1ll*(l+w)*(w-l+1)>>1))u=w;
		else v=w-1;
	}
	int L=u-l+1;
	u=l,v=r+1;
	while(u<v){
		int w=(u+v+1)>>1;
		if(val<=(1ll*(w+r)*(r-w+1)>>1))u=w;
		else v=w-1;
	}
	int R=r-v+1;
	return L>=R;
}
void func(int l,int r,ll val){
//	printf("FUNC:[%d,%d,%lld]\n",l,r,val);
	if(val==0)return;
	for(int i=1;i<=r-l+1;i++){
		ll lav=val-1ll*i*l;
		if(!(lav>=(1ll*(i-1)*i>>1)&&lav<=(1ll*(r-l+r-l-i+1)*i>>1)))continue;
//		printf("UGUGU:%d,%d\n",i,lav);
		vector<int>w;
		lav-=(1ll*(i-1)*i>>1);
		for(int j=0;j<i;j++)w.push_back(l+j);
		for(int j=i-1;j>=0;j--){
			if(lav<=(r-l+1)-i){w[j]+=lav,lav=0;break;}
			lav-=(r-l+1)-i;
			w[j]+=(r-l+1)-i;
		}
//		for(auto x:w)printf("%d ",x);puts("");
//		if(lav)exit(0);
		assert(!lav);
		for(auto x:w)b[x]=1;
		return;
	}
	assert(0);
}
int P[200100],Q[200100],f[200100],m,mus[200100];
bool F[200100],V[200100];
bool vis[200100];
void amin(){
	bool az=true;memset(mus,-1,sizeof(mus));
	for(int i=1;i<=n;i++)if(a[i]){
		az&=(a[i]<=1);
		if(!m){m++,P[m]=Q[m]=i;continue;}
		if(a[i]==a[P[m]]&&mus[m]!=0){mus[m]=1;Q[m]=i;continue;}
		if(a[i]==a[P[m]]+1){mus[m]=0;Q[m]=i;continue;}
		m++,P[m]=Q[m]=i;
	};
	if(az){for(int i=1;i<=n;i++)b[i]=0;pr();return;}
//	for(int i=1;i<=m;i++)printf("[%d,%d:%lld(%d)]\n",P[i],Q[i],a[P[i]],mus[i]);
	if(m==1){
		if(mus[1]!=1&&check(Q[1]+1,n,a[P[1]]-P[1])){
			b[P[1]]=1,func(Q[1]+1,n,a[P[1]]-P[1]),pr();
			return;
		}
		assert(mus[1]!=0);
		for(int i=1;i<=n;i++)if(!a[i]&&check(max(Q[1],i)+1,n,a[P[1]]-i-1)){
			b[i]=1,func(max(Q[1],i)+1,n,a[P[1]]-i-1),pr();
			return;
		}
		assert(0);
		return;
	}
	memset(f,-1,sizeof(f));
	if(mus[m]!=1&&check(Q[m]+1,n,a[P[m]]-P[m]))vis[m]=true;
	if(mus[m]!=0)for(int i=P[m]-1;i>Q[m-1];i--)if(check(Q[m]+1,n,a[P[m]]-1-i))
		{f[m]=i;break;}
	for(int i=m-1;i>=2;i--){
		if(mus[i]!=1){
			if(vis[i+1]&&check(Q[i]+1,P[i+1]-1,a[P[i]]-a[P[i+1]]-P[i]))
				vis[i]=true,V[i]=false;
			if(f[i+1]!=-1&&check(Q[i]+1,f[i+1]-1,a[P[i]]-(a[P[i+1]]-1)-P[i]))
				vis[i]=true,V[i]=true;
		}
		if(mus[i]!=0)for(int j=P[i]-1;j>Q[i-1];j--){
			if(vis[i+1]&&check(Q[i]+1,P[i+1]-1,a[P[i]]-1-a[P[i+1]]-j))
				{f[i]=j,F[i]=false;break;}
			if(f[i+1]!=-1&&check(Q[i]+1,f[i+1]-1,(a[P[i]]-1)-(a[P[i+1]]-1)-j))
				{f[i]=j,F[i]=true;break;}
		}
	}
	int rp=-1;bool tp;
	if(vis[2])for(int j=P[2]-1;j;j--){
		if(j==P[1]){
			if(mus[1]==1)continue;
			if(check(Q[1]+1,P[2]-1,a[P[1]]-a[P[2]]-j))rp=j,tp=false;
			continue;
		}
		if(a[j]||mus[1]==0)continue;
		if(check(max(Q[1],j)+1,P[2]-1,(a[P[1]]-1)-a[P[2]]-j))rp=j,tp=false;	
	}
	if(f[2]!=-1)for(int j=f[2]-1;j;j--){
		if(j==P[1]){
			if(mus[1]==1)continue;
			if(check(Q[1]+1,f[2]-1,a[P[1]]-(a[P[2]]-1)-j))rp=j,tp=true;
		}
		if(a[j]||mus[1]==0)continue;
		if(check(max(Q[1],j)+1,f[2]-1,(a[P[1]]-1)-(a[P[2]]-1)-j))rp=j,tp=true;
	}
	int i=n+1,j,k;
	if(mus[1]!=0&&a[P[1]]==a[P[2]]+1&&vis[2])j=P[2];
	else{
		i=rp,j=(tp?f[2]:P[2]);
		if(i==P[1])b[P[1]]=1,func(Q[1]+1,j-1,a[P[1]]-(a[P[2]]-(j!=P[2]))-P[1]);
		else b[i]=1,func(max(Q[1],i)+1,j-1,(a[P[1]]-1)-(a[P[2]]-(j!=P[2]))-i);
	}
	for(i=2;i<m;i++,j=k){
		if(j==P[i])k=(V[i]?f[i+1]:P[i+1]);
		else k=(F[i]?f[i+1]:P[i+1]);
		b[j]=1,func(Q[i]+1,k-1,(a[P[i]]-(j!=P[i]))-(a[P[i+1]]-(k!=P[i+1]))-j);
	}
	b[j]=1,func(Q[m]+1,n,(a[P[m]]-(j!=P[m]))-j),pr();
}
#ifndef Troverld 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[n-i+1]);
	amin();
	return 0;
}
#else
mt19937 rnd(17680321);
int main(){
	for(int t=1;t<=1000;t++){
		n=rnd()%10+1;
		printf("%d:%d\n",t,n);
		for(int i=1;i<=n;i++)a[i]=rnd()&1,b[i]=0;
		for(int i=1;i<=n;i++)printf("%lld ",a[i]);puts("");mina();
		for(int i=1;i<=n;i++)a[i]=((rnd()&1)?b[i]:0),b[i]=0;
		for(int i=1;i<=n;i++)printf("%lld ",a[i]);puts("");
		amin();
		memset(P,0,sizeof(P)),memset(Q,0,sizeof(Q)),m=0,memset(vis,false,sizeof(vis));
		memset(F,false,sizeof(F)),memset(V,false,sizeof(V));
		static int c[200100];
		for(int i=1;i<=n;i++)c[i]=a[i],a[i]=b[i],b[i]=0;mina();
		for(int i=1;i<=n;i++)assert(!c[i]||c[i]==b[i]),c[i]=b[i]=0;
	}
	return 0;
}
#endif