#include<bits/stdc++.h>
#define ll long long
#define N 1005
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,a[N],cnt0,cnt1;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>t;
 	while(t--){
 		cin >> n;
 		cnt0 = cnt1 = 0;
 		rep(i,1,n){
 			cin>>a[i];
 			if(a[i] == 0) cnt0++;
 			else cnt1++;
 		}
 		//if(cnt0&1) cnt0--;
 		if(cnt1&1) cnt1--;
 		cout << max(cnt0,cnt1) << endl;
 		if(cnt0 > cnt1) rep(i,1,cnt0) cout << "0 ";
 		else rep(i,1,cnt1) cout << "1 ";
 		cout << endl;
 	}
	return 0;
}