#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,p,k,a[N],b[N],c[N];
int x,y;
char s[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>p>>k;
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)a[i]=s[i]-'0';
		for(int i=0;i<=n-p;++i)a[i]=a[i+p];
		n-=p;
		cin>>x>>y;
		for(int i=0;i<k;++i)b[i]=0;
		for(int i=0;i<=n;++i)if(a[i])b[i%k]++;
		ll ans=1e18;
		int tot=0;
		for(int i=0;i<=n;++i){
			ans=min(ans,1ll*((n-i)/k+1-b[i%k])*x+1ll*i*y);
			if(a[i])b[i%k]--;
		}
		cout<<ans<<endl;
	}
}