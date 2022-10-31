#include<bits/stdc++.h>
using namespace std;
const int Q=1000000007;
int main(){
	int n,m;
	string T;
	cin>>n>>m;
	cin>>T;
	vector<int> f;
	vector<int> x;
	vector<bool> suf;
	f.resize(T.size());
	suf.resize(T.size());
	x.resize(m);
	for(int i=0;i<m;i++){
		cin>>x[i];
		--x[i];
	}
	int l=-1,cnt=0;
	long long ans=1;
	f[0]=-1;
	for(int i=1; i<T.size();i++){
		while(T[i]!=T[l+1] && l>=0) l=f[l];
		if(T[i]==T[l+1]) l=l+1;
		f[i] = l;
	}
	for(int i=T.size()-1;i>=0;i=f[i]){
		suf[i]=true;
	}
	if(!m){
		cnt=n;
	}
	else{
		cnt+=x[0];
		cnt+=n-(x[m-1]+T.size());
	}
	for(int i=0;i<m-1;i++){
		if(x[i+1]>=x[i]+T.size()) cnt+=x[i+1]-x[i]-T.size();
		else if(!suf[T.size()+x[i]-x[i+1]-1]) ans=0;
	}
	for(int i=0;i<cnt;i++){
		ans=ans*26%Q;
	}
	cout<<ans<<endl;
	return 0;
}