#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n;

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		vector<int>ans;
		ans.push_back(0);
		for(int i=1,last;i<=n;i=last+1){
			last=n/(n/i);
			ans.push_back(n/i);
		}
		cout<<ans.size()<<endl;
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
		cout<<endl;
	}
}