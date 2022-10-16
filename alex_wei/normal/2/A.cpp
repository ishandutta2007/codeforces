#include<bits/stdc++.h>
using namespace std;
#define ll long long
map <string,int> c;
int n,sc[1005],mx,cnt,num[1005],sc2[1005];
string s[1005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>num[i];
		if(!c[s[i]])c[s[i]]=++cnt;
		sc[c[s[i]]]+=num[i];
	}
	for(int i=1;i<=cnt;i++)
		mx=max(mx,sc[i]);
	for(int i=1;i<=n;i++){
		sc2[c[s[i]]]+=num[i];
		if(sc2[c[s[i]]]>=mx&&sc[c[s[i]]]==mx)
			cout<<s[i],exit(0);
	}
	return 0;
}