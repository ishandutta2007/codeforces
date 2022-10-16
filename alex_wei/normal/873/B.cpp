#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int f,n,ans,q[N<<1],m[N<<1];
string s;
int main(){
	cin>>n>>s;
	q[f+N]=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')f--;
		else f++;
		if(!q[f+N])q[f+N]=i+2;
		m[f+N]=i+2;
	}
	for(int i=0;i<=(N<<1);i++)
		if(q[i])
			ans=max(ans,m[i]-q[i]);
	cout<<ans;
	return 0;
}