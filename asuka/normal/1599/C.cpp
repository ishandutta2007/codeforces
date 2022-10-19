#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
using db = long double;
int n;
db P;
int s3(int x) {return x * (x - 1) * (x - 2) / 6;}
int s2(int x) {return (x * (x - 1)) / 2;}
bool check(int x) {
	db nP = (db) (s3(x) + (s2(x) * (n - x)) + (db) (s2(n - x) * x / 2)) / (s3(n));
	return nP >= P;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n >> P;
	int ans = 0;
	rep(i, 0, n) if(check(i)) {ans = i; break;}
	cout << ans << endl;
	return 0;
}