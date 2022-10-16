#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
int q;
string s,t;
int main()
{
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		reverse(s.begin(),s.end());
		reverse(t.begin(),t.end());
		for(int i=0;i<t.size();i++)
			if(t[i]=='1'){
				for(int j=i;j<s.size();j++)
					if(s[j]=='1'){
						cout<<j-i<<endl;
						break;
					}
				break;
			}
	}
	return 0;
}