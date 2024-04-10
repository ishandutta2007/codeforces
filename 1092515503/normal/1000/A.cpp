#include<bits/stdc++.h>
using namespace std;
int n,res;
string str;
map<string,int>m;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>str,m[str]++;
	for(int i=1;i<=n;i++)cin>>str,m[str]--;
	for(map<string,int>::iterator i=m.begin();i!=m.end();i++)res+=abs(i->second);
	cout<<res/2<<endl;
	return 0;
}