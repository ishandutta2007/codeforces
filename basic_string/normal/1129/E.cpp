#include<bits/stdc++.h>
using namespace std;
enum{N=509};
vector<pair<int,int>>ans;
basic_string<int>s;
int sz[N],p[N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k,l,r,m;
	cin>>n,sz[1]=n,p[1]=1;
	for(i=2;i<=n;++i){
		for(cout<<n-1<<'\n',j=2;j<=n;++j)cout<<j<<' ';
		cout<<"\n1\n1\n"<<i<<endl,cin>>sz[i],p[i]=i;
	}
	sort(p+1,p+n+1,[](int x,int y){return sz[x]>sz[y];});
	for(k=n;k;s+=p[k--])while(size(s)){
		l=0,r=size(s)-1;
		while(l<=r){
			m=l+r>>1;
			for(cout<<m+1<<'\n',i=0;i<=m;++i)cout<<s[i]<<' ';
			cout<<"\n1\n1\n"<<p[k]<<endl;
			if(cin>>j,j)r=m-1;else l=m+1;
		}
		if(l==size(s))break;
		ans.push_back({p[k],s[l]}),s.erase(l,1);
	}
	cout<<"ANSWER\n";
	for(auto o:ans)cout<<o.first<<' '<<o.second<<'\n';
	cout<<endl;
	return 0;
}