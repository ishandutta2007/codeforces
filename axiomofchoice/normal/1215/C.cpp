#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
string s1,s2;
int len;
vector<int> a[2];
int main(){
	//ios_base::sync_with_stdio(false);
	cin>>len;
	cin>>s1>>s2;
	rep(i,0,len){
		if(s1[i]==s2[i])
			continue;
		else
			a[s1[i]=='a'].push_back(i+1);
	}
	int ans=a[0].size()/2+a[1].size()/2;
	if((a[0].size()%2) ^ (a[1].size()%2)){
		cout<<-1<<endl;
		return 0;
	}
	else{
		if(a[0].size()%2)ans+=2;
		cout<<ans<<endl;
	}
	while(a[0].size()>=2){
		cout<<a[0].back()<<' ';
		a[0].pop_back();
		cout<<a[0].back()<<endl;
		a[0].pop_back();
	}
	while(a[1].size()>=2){
		cout<<a[1].back()<<' ';
		a[1].pop_back();
		cout<<a[1].back()<<endl;
		a[1].pop_back();
	}
	if(a[0].size()){
		cout<<a[0].back()<<' ';
		cout<<a[0].back()<<endl;
		cout<<a[0].back()<<' ';
		cout<<a[1].back()<<endl;
	}
	return 0;
}