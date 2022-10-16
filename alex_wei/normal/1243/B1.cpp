#include<bits/stdc++.h>
using namespace std;
#define ll long long
int k,n;
string s,t;
int main()
{
	cin>>k;
	while(k--){
		cin>>n>>s>>t;
		int ans=0,p1=0,p2=0,pd=0;
		for(int i=0;i<s.size();i++)
			if(s[i]!=t[i]){
				if(ans==2){pd=1;break;}
				if(!ans)p1=i;
				else p2=i;
				ans++;
			}
		if(pd||ans==1){cout<<"No\n";continue;}
		if(ans==0){cout<<"Yes\n";continue;}
		if(s[p1]!=s[p2]||t[p2]!=t[p1])cout<<"No\n";
		else cout<<"Yes\n";
	}
    return 0;
}