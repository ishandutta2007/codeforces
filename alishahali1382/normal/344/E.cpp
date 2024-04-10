#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=100 * 1000 + 10;

int n, m;
ll p[MAXN];
ll h[MAXN];

bool check(ll t){
	ll i=0, j=0, jj, tmp;
	for (;i<n && j<m; i++){
		//cout<<i<<' '<<j<<endl;
		if (h[i]<p[j]){
			while (p[j]<=h[i]+t && j<m) j++;
			continue ;
		}
		if (h[i]-t>p[j]) return false;
		// mode 1
		jj=j;
		tmp=max(t-2*(h[i]-p[j]), 0LL);
		while (p[jj]<=h[i]+tmp && jj<m) jj++;
		//mode 2
		tmp=max((t-(h[i]-p[j]))/2, 0LL);
		while (p[j]<=h[i]+tmp && j<m) j++;
		
		j=max(j, jj);
	}
	return j==m;
}

ll f(ll l, ll r){
	//cout<<l<<' '<<r<<endl;
	if (r-l==1) return l;
	if (r-l==2){
		//cout<<"debug"<<endl;
		if (check(l)) return l;
		return l+1;
	}
	
	ll mid=(l+r)/2;
	if (check(mid)) return f(l, mid+1);
	return f(mid, r);
}

int main(){
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m;
	for (int i=0; i<n; i++) cin>>h[i];
	for (int i=0; i<m; i++) cin>>p[i];
	cout<<f(0LL, 100000000000000LL)<<endl;
	return 0;
}