#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,x[N],y[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		if(n&1)cout<<1<<endl;
		else cout<<1ll*(y[n/2+1]-y[n/2]+1)*(x[n/2+1]-x[n/2]+1)<<endl;
	}
}