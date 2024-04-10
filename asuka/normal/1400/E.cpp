#include<bits/stdc++.h>
#define ll long long
#define N 5005
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,a[N];
int solve(int l,int r){
	if(l > r) return 0;
	if(l == r) return a[l]!=0;
	int pos = min_element(a+l,a+r+1)-a,Min = a[pos];
	
	//cout << pos <<  ' ' << l << ' ' << r << endl;
	rep(i,l,r) a[i] -= Min;
	return min(solve(l,pos-1)+solve(pos+1,r)+Min,r-l+1);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>n;
 	rep(i,1,n) cin>>a[i];
 	//cout << min_element(a+2,a+3+1);
 	cout << solve(1,n);
	return 0;
}