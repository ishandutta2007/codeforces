#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 1000010
#define int ll
int n,t,s,s2,l[200010],r[200010];
vector<int> a;
bool work(int m){
	a.clear();
	repeat(i,0,n){
		if(r[i]<m)continue;
		a.push_back(max(0ll,m-l[i]));
	}
	int s3=s2;
	sort(a.begin(),a.end());
	repeat(i,0,a.size()){
		s3-=a[i];
		if(s3<0)break;
		if(i>=n/2)return true;
	}
	return false;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>s; s2=s;
		repeat(i,0,n){
			cin>>l[i]>>r[i];
			s2-=l[i];
		}
		int L=0,R=(ll)2e16,m;
		while(L<=R){
			m=(L+R)/2;
			if(work(m))L=m+1;
			else R=m-1;
		}
		cout<<R<<endl;
	}
	return 0;
}