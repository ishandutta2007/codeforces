#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,m,k;
int a[N];

pair<int,int> check(int m){
	int L=0,R=1e9;
	for(int i=1;i<=n;++i)
	if(a[i]==-1){
		if(i>1&&a[i-1]!=-1){
			L=max(L,a[i-1]-m);
			R=min(R,a[i-1]+m);
		}
		if(i<n&&a[i+1]!=-1){
			L=max(L,a[i+1]-m);
			R=min(R,a[i+1]+m);
		}
	}
	return make_pair(L,R);
}

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		m=0;
		for(int i=1;i<n;++i)
		if(a[i]!=-1&&a[i+1]!=-1){
			m=max(m,abs(a[i]-a[i+1]));
		}
		int l=m,r=1e9;
		while(l!=r){
			int mid=l+r>>1;
			pair<int,int> ret=check(mid);
			if(ret.second>=ret.first)r=mid;
			else l=mid+1;
		}
		cout<<l<<" "<<check(l).first<<endl;
	}
}