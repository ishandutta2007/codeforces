#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n;
ll a[N],ans;
map<ll,int> last;

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int pmax=0;
	for(int i=1;i<=n;++i){
		a[i]+=a[i-1];
		int p;
		if(!last[a[i]])p=(a[i]==0);
		else p=last[a[i]]+1;
		p=max(pmax,p);
		last[a[i]]=i;
		ans+=i-p;
		pmax=max(pmax,p);
	}
	cout<<ans<<endl;
}