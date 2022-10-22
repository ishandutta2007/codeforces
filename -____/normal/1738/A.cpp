#include<bits/stdc++.h>
using namespace std;
const int N = 111111;
int n,m,a[N],b[N];
vector<int> f,g;
int main(){
	int T,i,x;
	long long s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		f.clear(),g.clear();
		s=0;
		for(i=1;i<=n;i++){
			s+=b[i];
			if(a[i])
				f.push_back(b[i]);
			else
				g.push_back(b[i]);
		}
		sort(f.begin(),f.end());
		sort(g.begin(),g.end());
		n=f.size(),m=g.size();
		if(n==m){
			printf("%lld\n",s*2-min(f[0],g[0]));
			continue;
		}
		x=min(n,m);
		for(i=1;i<=x;i++)
			s+=f[n-i]+g[m-i];
		printf("%lld\n",s);
	}
	return 0;
}