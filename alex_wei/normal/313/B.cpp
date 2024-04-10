#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string s;
int n,pre[N];
int main(){
	cin>>s>>n;
	for(int i=1;i<s.size();i++)pre[i]=s[i]==s[i-1];
	for(int i=1;i<s.size();i++)pre[i]+=pre[i-1];
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		cout<<pre[y-1]-pre[x-1]<<endl;
	}
	return 0;
}