#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll mod = 998244353;

int T,n,k;

int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		vector<int> a;
		for(int i=k+1;i<=n;++i)a.push_back(i);
		for(int i=(k+1)/2;i<k;++i)a.push_back(i);
		sort(a.begin(),a.end());
		cout<<a.size()<<endl;
		for(int i=0;i<a.size();++i)cout<<a[i]<<" ";
		cout<<endl;
	}
}