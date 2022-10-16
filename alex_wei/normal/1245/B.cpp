#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a,b,c;
string s;
int main()
{
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>c>>s;
		int ans=0;
		string t="";
		for(int i=0;i<s.size();i++){
			if(s[i]=='R'){
				if(b)b--,ans++,t+='P';
				else t+='X';
			}
			if(s[i]=='P'){
				if(c)c--,ans++,t+='S';
				else t+='X';
			}
			if(s[i]=='S'){
				if(a)a--,ans++,t+='R';
				else t+='X';
			}
		}
		if(ans>=(n-1)/2+1){
			puts("YES");
			for(int i=0;i<t.size();i++){
				if(t[i]=='X'){
					if(a)a--,t[i]='R';
					else if(b)b--,t[i]='P';
					else c--,t[i]='S';
				}
			}
			cout<<t<<endl;
		}
		else puts("NO");
	}
    return 0;
}