#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=300 * 1000 + 10;
const int inf=1000000001;

ll n, ans, ansx, ansy;
ll A[MAXN][2];
ll xl[MAXN];
ll xr[MAXN];
ll yl[MAXN];
ll yr[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	yl[0]=yr[n+1]=inf;
	for (int i=1; i<=n; i++){
		cin>>A[i][0]>>A[i][1];
		xl[i]=max(xl[i-1], A[i][0]);
		yl[i]=min(yl[i-1], A[i][1]);
		//cerr<<xl[i]<<endl;
	}
	
	for (int i=n; i>=1; i--){
		xr[i]=max(xr[i+1], A[i][0]);
		yr[i]=min(yr[i+1], A[i][1]);
	}
	/*
	for (int i=1; i<=n; i++){
		cerr<<yr[i]<<endl;
	}*/
	
	for (int i=1; i<=n; i++){
		ans=max(ans, min(yl[i-1], yr[i+1]) - max(xl[i-1], xr[i+1]));
		//cout<<min(yl[i-1], yr[i+1]) - max(xl[i-1], xr[i+1])<<endl;
	}
	
	cout<<ans<<endl;
	
	return 0;
}