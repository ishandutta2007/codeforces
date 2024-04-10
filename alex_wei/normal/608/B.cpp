#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t; 
ll sum,pre[200005];
int main(){
	cin>>s>>t;
	for(int i=1;i<=t.size();i++)pre[i]=pre[i-1]+(t[i-1]=='1');
	for(int i=0;i<s.size();i++){
		ll m=pre[t.size()-s.size()+i+1]-pre[i];
		if(s[i]=='1')sum+=t.size()-s.size()+1-m;
		else sum+=m;
	}
	cout<<sum;
    return 0;
}