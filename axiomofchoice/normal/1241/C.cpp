#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
string s,t;
set<char> ss;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll a,b,c,n,x,y,k;
ll p[200010];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		repeat(i,1,n+1){
			cin>>p[i];
			p[i]/=100;
		}
		sort(p+1,p+n+1);
		cin>>x>>a;
		cin>>y>>b;
		if(x<y)swap(x,y),swap(a,b);
		cin>>k;
		c=a/gcd(a,b)*b;
		ll l=0,r=n,m,top,cnt;
		while(l<=r){
			m=(l+r)>>1;
			cnt=0;
			top=n;
			repeat(i,0,m/c)
				cnt+=p[top--]*(x+y);
			repeat(i,0,m/a-m/c)
				cnt+=p[top--]*x;
			repeat(i,0,m/b-m/c)
				cnt+=p[top--]*y;
			//cout<<m<<' '<<cnt<<endl;
			if(cnt<k)
				l=m+1;
			else if(cnt>=k)
				r=m-1;
		}
		if(l>n)cout<<-1<<endl;
		else cout<<l<<endl;
	}
	return 0;
}