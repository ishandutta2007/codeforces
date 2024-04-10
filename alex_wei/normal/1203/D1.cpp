#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
string s,t;
int ans=0;
bool check(string p)
{
	int poia=0,poib=0;
	while(poia<p.size()&&poib<t.size()){
		if(p[poia]==t[poib])poib++;
		poia++;
	}
	return poib==t.size();
}
int main()
{
	cin>>s>>t;
	for(int i=1;i<=s.size();i++)
		for(int j=i;j<=s.size();j++){
			string f="";
			for(int k=1;k<i;k++)
				f+=s[k-1];
			for(int k=j+1;k<=s.size();k++)
				f+=s[k-1];
			if(check(f))ans=max(ans,j-i+1);
		}
	cout<<ans;
	return 0;
}