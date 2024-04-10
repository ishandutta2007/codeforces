#include <bits/stdc++.h>
using namespace std;
int q,need[128],have[128];
string s,t,p; 
int main()
{
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>s>>t>>p;
		memset(have,0,sizeof(have));
		memset(need,0,sizeof(need));
		int poi=0,pd=1;
		for(int j=0;j<s.size();j++){
			while(poi<t.size()&&t[poi]!=s[j])
				need[t[poi]]++,poi++;
			if(poi>=t.size()){pd=0;break;}
			poi++;
		}
		while(poi<t.size())need[t[poi]]++,poi++;
		for(int j=0;j<p.size();j++)
			have[p[j]]++;
		for(int j=0;j<128;j++){
			if(need[j]>have[j]){pd=0;break;}
		}
		if(pd)cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}