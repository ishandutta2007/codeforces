#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,k;
int p[N];
ll ans1,ans2=1;

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>p[i];
	for(int i=n;i>=n-k+1;--i)ans1+=i;
	int last=0;
	for(int i=1;i<=n;++i)
	if(p[i]>=n-k+1){
		if(last){
			ans2=(ans2*(i-last))%998244353;
		}
		last=i;
	}
	cout<<ans1<<" "<<ans2<<endl;
}