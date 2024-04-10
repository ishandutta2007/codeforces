#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
map <string,string> mp;
map <string,bool> ck;
int n,cnt;
string od,nw,s[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>od>>nw;
		if(!ck[od])s[++cnt]=od;
		mp[od]=nw;
		ck[od]=ck[nw]=1;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		cout<<s[i]<<" ";
		while(mp.find(s[i])!=mp.end())s[i]=mp[s[i]];
		cout<<s[i]<<endl;
	}
	return 0;
}