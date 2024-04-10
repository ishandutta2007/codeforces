#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,f[100005],a[100005],la[100005],ans[100005],cnt,l[100005],r[100005];
int get(int x){return x==f[x]?x:f[x]=get(f[x]);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i),f[i]=la[i]=i,l[i]=i-1,r[i]=i+1;
		l[1]=n,r[n]=1;
		cnt=0;
		int C=n;
		for(int i=n-1;i;--i)if(__gcd(a[i],a[i+1])>1)f[i]=f[i+1],--C;
		if(C>1&&__gcd(a[n],a[1])>1)f[n]=1,--C;
		int k=1,L=0;
		while(L<=n&&cnt<n-1){
			k=la[get(k)];
			int o=r[k];
			if(__gcd(a[k],a[o])>1)++L;
			else{
				ans[++cnt]=o;
				if(cnt==n-1) break;
				r[k]=r[o];
				l[r[k]]=k;
				if(la[get(o)]==o){
					f[get(k)]=o;
					la[get(k)]=k;
					--C;
				}
				if(get(k)!=get(r[k])&&__gcd(a[k],a[r[k]])>1){
					f[get(k)]=r[k];
				}
			}
			k=r[k];
		}
		if(cnt==n-1&&a[k]==1)ans[++cnt]=k;
		printf("%d",cnt);
		for(int i=1;i<=cnt;++i)printf(" %d",ans[i]);
		printf("\n");
	}
    return 0;
}