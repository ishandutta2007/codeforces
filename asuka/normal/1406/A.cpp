#include<bits/stdc++.h>
#define ll long long
#define N 105
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,cnt[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>t;
 	while(t--){
 		cin>>n;
 		rep(i,0,100) cnt[i] = 0;
 		rep(i,1,n){
 			int val;
 			cin>>val;cnt[val]++;
 		}
 		int f1,f2;f1 = f2 = -1;
 		rep(i,0,n){
 			if(f1 == i-1&&cnt[i] >= 1) f1++;
 			if(f2 == i-1&&cnt[i] >= 2) f2++;
 		}
 		cout << max(f1+f2+2,0) << endl;
 	}
	return 0;
}