#include<bits/stdc++.h>
#define ll long long
#define N 10015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,a[N],vis[N];
int get(int x,int y){
	cout << "? " << x <<  ' ' << y << endl;
	cout.flush();
 	cout << endl;
 	cout.flush();
 	int temp;
 	cin >> temp;
 	return temp;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
 	cin>>n;
 	rep(i,1,n)
 	rep(i,1,n){
 		if(a[i]) continue;
 		rep(j,1,n){
 			if(i == j) continue;
 			if(a[j]) continue;
 			int p = get(i,j),q = get(j,i);
 			if(p > q) a[i] = p,vis[p] = 1;
 			else a[j] = q,vis[q] = 1;
 			break;
 		}
 	}
 	int lost = 0;
 	rep(i,1,n){
 		if(!vis[i]) lost = i;
 	}
 	rep(i,1,n) if(!a[i]) a[i] = lost;
 	cout << "! ";
 	cout.flush();
 	rep(i,1,n) cout << a[i] << ' ';
 	cout.flush();
	return 0;
}