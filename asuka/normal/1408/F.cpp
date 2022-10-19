#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int x,n;
vector<pii> v;
void solve(int l,int r){
	if(r-l+1==2){
		v.pb(mp(l,r));
		return;
	}
	int mid = (l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	rep(i,1,mid-l+1){
		//cout
		v.pb(mp(l+i-1,r-i+1));
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>n;
 	if(n==1){
 		puts("0");
 		return 0;
 	}
 	per(i,0,20){
 		if((1<<i)&n){
 			//cout << "fuckA:" << i << endl;
 			//cout << n-(1<<i)+1 << '#' << n << endl;
 			solve(1,(1<<i));
 			solve(n-(1<<i)+1,n);
 			break;
 		}
 	}
 	cout << v.size() << endl;;
 	for(auto u:v) cout << u.fi << ' ' << u.se << endl;
	return 0;
}