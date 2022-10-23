#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[100005],b[100005],ans[100005];
pair<int,int> p[100005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		for(int i=1;i<=n;++i)scanf("%d",b+i);
		for(int i=1;i<=n;++i)p[i]=mp(-a[i],i),ans[i]=0;
		sort(p+1,p+n+1);
		int k=p[1].second;
		ans[k]=1;
		int o=b[k];
		vector<int> v;
		for(int i=2;i<=n;++i){
			int x=p[i].second;
			v.pb(x);
			if(b[x]>o){
				for(int j=0;j<v.size();++j)o=min(o,b[v[j]]),ans[v[j]]=1;
				v.clear();
			}
		}
		for(int i=1;i<=n;++i)printf("%d",ans[i]);
		printf("\n");
	}
    return 0;
}