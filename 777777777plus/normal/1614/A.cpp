#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,l,r,k;
int a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>l>>r>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;++i)
		if(a[i]>=l&&a[i]<=r){
			if(k>=a[i])k-=a[i],++ans;
		}
		cout<<ans<<endl;
	}
	
}