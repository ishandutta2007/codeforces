#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,a[N],b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>n;
 	rep(i,1,n) cin>>a[i];
 	sort(a+1,a+n+1);int l = 1,r = n;
 	rep(i,1,n){
 		if(i&1) b[i] = a[r--];
 		else b[i] = a[l++];
 	}
 	int cnt = 0;
 	rep(i,2,n-1){
 		if(b[i] < b[i-1]&&b[i] < b[i+1]) cnt++;
 	}
 	cout << cnt << endl;
 	rep(i,1,n) cout << b[i] << ' ';
	return 0;
}