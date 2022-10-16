#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
int t,n,a[N];
vector <int> buc[N];
void solve(){
	for(int i=1;i<37;i++)buc[i].clear();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=2;j*j<=a[i];j++)if(a[i]%j==0){
			buc[j].push_back(i);
			break;
		}
	}
	int ans=0;
	for(int i=1;i<37;i++)ans+=buc[i].size()>0;
	cout<<ans<<endl;
	for(int i=1;i<37;i++)if(buc[i].size()){
		for(auto it:buc[i])a[it]=ans;
		ans--;
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	puts("");
}
int main(){
	cin>>t;
	while(t--)solve();
	return 0; 
}