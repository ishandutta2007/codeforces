#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const ll INF=~0ull>>2;
#define int ll
vector<int> a,b,c;
ll ans;
template<typename T> T sqr(const T &x){return x*x;}
int cal(int x,int y,int z){
	return sqr(x-y)+sqr(y-z)+sqr(z-x);
}
template<typename T>
int pcal(T x,T y,T z){
	return cal(*x,*y,*z);
}
signed main(){
	int T; cin>>T;
	while(T--){
		ans=INF*2;
		{
			int n1,n2,n3,x; cin>>n1>>n2>>n3;
			a.clear(); b.clear(); c.clear();
			repeat(i,0,n1)cin>>x,a.push_back(x);
			repeat(i,0,n2)cin>>x,b.push_back(x);
			repeat(i,0,n3)cin>>x,c.push_back(x);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		auto p1=a.begin(),p2=b.begin(),p3=c.begin();
		while(1){
			int now=INF*2; auto nowp=&p1; ans=min(ans,pcal(p1,p2,p3));
			if(p1!=a.end()-1 && pcal(p1+1,p2,p3)<now)now=pcal(p1+1,p2,p3),nowp=&p1;
			if(p2!=b.end()-1 && pcal(p1,p2+1,p3)<now)now=pcal(p1,p2+1,p3),nowp=&p2;
			if(p3!=c.end()-1 && pcal(p1,p2,p3+1)<now)now=pcal(p1,p2,p3+1),nowp=&p3;
			if(now==INF*2)break;
			(*nowp)++;
		}
		cout<<ans<<endl;
	}
	return 0;
}