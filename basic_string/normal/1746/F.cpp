#include<bits/stdc++.h>
using namespace std;
enum{N=300009};
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
map<int,int>mp;
int a[N],id;
long long w[N*2][31],tmp[31],tr[N][31];
int get(int x){
	if(mp.count(x))return mp[x];
	mp[x]=++id;
	for(int o=0;o<30;++o)w[id][o]=rd();
	return id;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,q,i,j,l,r,k;
	cin>>n>>q;
	for(i=1;i<=n;++i)cin>>j,a[i]=get(j);
	for(i=1;i<=n;++i){
		for(j=0;j<30;++j)tr[i][j]+=w[a[i]][j];
		int k=i+(i&-i);
		if(k<=n)for(j=0;j<30;++j)tr[k][j]+=tr[i][j];
	}
	while(q--){
		cin>>i;
		if(i==1){
			cin>>l>>r;
			for(j=0;j<30;++j)tmp[j]=-w[a[l]][j];
			a[l]=get(r);
			for(j=0;j<30;++j)tmp[j]+=w[a[l]][j];
			for(i=l;i<=n;i+=i&-i){
				for(j=0;j<30;++j)tr[i][j]+=tmp[j];
			}
		}else{
			cin>>l>>r>>k;
			if((r-l+1)%k){cout<<"NO\n";continue;}
			memset(tmp,0,sizeof tmp);
			for(i=r;i;i-=i&-i)for(j=0;j<30;++j)
			tmp[j]+=tr[i][j];
			for(i=l-1;i;i-=i&-i)for(j=0;j<30;++j)
			tmp[j]-=tr[i][j];
			for(j=0;j<30;++j)if(tmp[j]%k){cout<<"NO\n";goto gg;}
			cout<<"YES\n";
			gg:; 
		}
	}
}