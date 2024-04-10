#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
map <string,int> mp;
int n,m,q,f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
string s,t; 
int main(){
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)cin>>s,mp[s]=i,f[i]=i,f[i+n]=i+n;
	for(int i=0;i<m;i++){
		int rel,u,v;
		cin>>rel>>s>>t;
		u=mp[s],v=mp[t];
		if(rel==1){
			if(find(u)==find(v+n))puts("NO");
			else puts("YES"),f[find(u)]=find(v),f[find(u+n)]=find(v+n);
		}
		else{
			if(find(u)==find(v))puts("NO");
			else puts("YES"),f[find(u)]=find(v+n),f[find(u+n)]=find(v);
		}
	}
	for(int i=0;i<q;i++){
		cin>>s>>t;
		int u=mp[s],v=mp[t];
		if(find(u)==find(v))puts("1");
		else if(find(u)==find(v+n))puts("2");
		else puts("3");
	}
	return 0;
}