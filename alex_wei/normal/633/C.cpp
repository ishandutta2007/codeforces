#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define puu pair<ull,ull>
#define mp make_pair
const int N=1e4+5;
const ull b1=131,b2=37;
int n,m,mx,rea[N],cnt;
string s,t,pre[N],ans[N];
set <puu> z;
puu has(string q){
	ull a=0,b=0;
	for(int i=0;i<q.size();i++){
		if(q[i]<'a')q[i]+=32;
		a=a*b1+q[i],b=b*b2+q[i];
	}
	return mp(a,b);
}
map <pair<ull,ull>,string> q;
int main(){
	cin>>n>>s>>m; reverse(s.begin(),s.end());
	for(int i=1;i<=m;i++)cin>>t,q[has(t)]=t,mx=max(mx,(int)t.size());
	for(int i=0;i<n;i++){
		if(i>0&&!rea[i])continue;
		ull a=0,b=0;
		int r=min(n,i+mx);
		for(int j=i+1;j<=r;j++){
			a=a*b1+s[j-1],b=b*b2+s[j-1];
			if(q.find(mp(a,b))!=q.end()){
				rea[j]=1;
				pre[j]=q[mp(a,b)];
			}
		}
	}
	int pos=n;
	while(pos!=0){
		ans[++cnt]=pre[pos];
		pos=pos-pre[pos].size();
	}
	for(int i=1;i<=cnt;i++)cout<<ans[i]<<" ";
	return 0;
}