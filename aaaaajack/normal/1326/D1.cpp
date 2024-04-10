#include<bits/stdc++.h>
#define N 200100
#define Q 998244353
#define sz(x) (x).size()
#define rep(i,a,b) for(int i=a; i<(b);i++)
using namespace std;
typedef vector<int> vi;

array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}
int main(){
	int t;
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		auto p=manacher(s);
		int n=s.size();
		int l=0,ans=-1,mx=0;
		while(l<n-1-l&&s[l]==s[n-1-l]) l++;
		ans=l+l;
		string out;
		for(int i=l;i<n-l;i++){
			int mn=min(i-l,n-l-1-i);
			if(p[1][i]>=mn){
				int tmp=1+2*(l+mn);
				if(tmp>ans){
					ans=tmp;
					mx=i;
				}
			}
		}
		for(int i=l;i<=n-l;i++){
			int mn=min(i-l,n-l-i);
			if(p[0][i]>=mn){
				int tmp=2*(l+mn);
				if(tmp>ans){
					ans=tmp;
					mx=i;
				}
			}
		}
		out=s.substr(0,l);
		out+=s.substr(mx-(ans-l*2)/2,ans-l*2);
		out+=s.substr(n-l,l);
		cout<<out<<endl;
	}
	return 0;
}