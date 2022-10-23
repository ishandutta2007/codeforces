#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,m,cnt[100005],a[100005],b[100005];
pair<int,int> p[100005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&m,&n);
		for(int i=1;i<=m;++i)cnt[i]=0;
		int N=(n+1)/2;
		for(int i=1;i<=n;++i){
			scanf("%d",&m);
			for(int j=1;j<=m;++j)scanf("%d",b+j);
			if(m==1)p[i]=mp(b[1],b[1]);
			else p[i]=mp(b[1],b[2]);
			++cnt[a[i]=b[1]];
		}
		for(int i=1;i<=n;++i){
			if(cnt[a[i]]>N){
				--cnt[a[i]];
				a[i]=p[i].second;
				++cnt[a[i]];
			}
		}
		bool b=0;
		for(int i=1;i<=n;++i)if(cnt[a[i]]>N)b=1;
		if(b)printf("NO\n");
		else{
			printf("YES\n");
			for(int i=1;i<n;++i)printf("%d ",a[i]);
			printf("%d\n",a[n]);
		}
	}
    return 0;
}