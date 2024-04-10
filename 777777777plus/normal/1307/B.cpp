#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T,n,x,a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>x;
		for(int i=1;i<=n;++i)cin>>a[i];
		int w=*max_element(a+1,a+n+1);
		bool flag=0;
		for(int i=1;i<=n;++i)
		if(a[i]==x){
			cout<<1<<endl;
			flag=1;
			break;
		}
		if(flag)continue;
		int ans=(x+w-1)/w;
		ans=max(ans,2);
		cout<<ans<<endl;
	}
}