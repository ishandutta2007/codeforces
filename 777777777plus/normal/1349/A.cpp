#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n;
vector<int> w[N];

int main(){
	cin>>n;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		for(int j=2;j*j<=x;++j)
		if(x%j==0){
			int t=0;
			while(x%j==0){
				x/=j;
				t++;
			}
			w[j].push_back(t);
		}
		if(x>1){
			w[x].push_back(1); 
		}
	}
	ll ans=1;
	for(int i=1;i<=2e5;++i)
	if(w[i].size()>n-2){
		sort(w[i].begin(),w[i].end());
		if(w[i].size()==n-1)ans*=pow(i,w[i][0]);
		else ans*=pow(i,w[i][1]);
	}
	cout<<ans<<endl;
}