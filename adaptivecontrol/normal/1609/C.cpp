#include<bits/stdc++.h>
using namespace std;
int T,e,n,a[200003],lst[200003],nxt[200003];
bool isp[1000003];
long long calc(vector<int>nw){
	long long ret=0;
	for(int i=0;i<nw.size();i++)
		if(nw[i]!=1)
			if(isp[nw[i]]){
				int l,r;
				for(l=i-1;l>=0;l--)
					if(nw[l]!=1)
						break;
				for(r=i+1;r<nw.size();r++)
					if(nw[r]!=1)
						break;
//				cout<<i<<' '<<l<<' '<<r<<endl;
				ret+=(1ll*(i-l)*(r-i)-1);
			}return ret;
}
int main(){
	cin>>T;
	memset(isp,1,sizeof(isp));
	for(int i=2;i<1000003;i++)
		if(isp[i])
			for(int j=i+i;j<1000003;j+=i)
				isp[j]=0;
	while(T--){
		cin>>n>>e;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		long long ans=0;
		for(int i=0;i<e;i++){
			vector<int>v;
			for(int j=i;j<n;j+=e)
				v.push_back(a[j]);
			ans+=calc(v);
		}
		cout<<ans<<endl;
	}
}