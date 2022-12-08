#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,a[N],id[N],p[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],id[i]=i;
		sort(id+1,id+n+1,[](int x,int y){return a[x]>a[y];});
		int r=0,l=0;
		ll ans=0;
		for(int i=1;i<=n;++i){
			if(i&1)p[id[i]]=++r;
			else p[id[i]]=--l;
			ans+=1ll*abs(p[id[i]])*2*a[id[i]];
		}
		cout<<ans<<endl;
		for(int i=0;i<=n;++i)cout<<p[i]<<" ";
		cout<<endl;
	}
	
}