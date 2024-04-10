#include<bits/stdc++.h>
using namespace std;
int f[44],a[109];
bool b[44];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	f[0]=f[1]=1;
	for(i=2;i<44;++i)f[i]=f[i-1]+f[i-2];
	for(cin>>T;T--;){
		cin>>n;
		long long sum=0;
		for(i=1;i<=n;++i)cin>>a[i],sum+=a[i];
		k=-1;
		long long sum2=0;
		for(i=0;i<44;++i)if(sum2+=f[i],sum2==sum){k=i;break;}
		if(k==-1||n>45){cout<<"NO\n";continue;}
		multiset<pair<int,int>>s;
		for(i=1;i<=n;++i)s.insert({a[i],k});
		memset(b,0,sizeof b);
		while(s.size()){
			auto i=*s.rbegin();
			s.erase(--s.end());
			for(j=i.second;j>=0;--j)
			if(!b[j]&&i.first>=f[j]){b[j]=1,i.first-=f[j],i.second=j-2;goto g2;}
			cout<<"NO\n";goto gg;
			g2:;
			if(i.first)s.insert(i);
		}cout<<"YES\n";gg:;
	}
}