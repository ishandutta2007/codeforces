#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n,a[105];
bool vis[105];
int main(){
	cin>>T;
	while(T--){
		vector<int> s1,s2;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);
		a[0]=-1;
		for(int i=1;i<=n;++i)
		if(a[i]==a[i-1])s2.push_back(a[i]);
		else s1.push_back(a[i]);
		for(int i=0;i<s1.size();++i)cout<<s1[i]<<" ";
		for(int i=0;i<s2.size();++i)cout<<s2[i]<<" ";
		cout<<endl;
	}
}