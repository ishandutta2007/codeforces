#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T,n,d,a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
		int ans=a[1];
		for(int i=2;i<=n;++i){
			while(a[i]&&d>=i-1)d-=i-1,a[i]--,ans++;
		}
		cout<<ans<<endl;
	}
}