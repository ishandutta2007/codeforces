/*
 * 	Meet me on the battlefield
 * 		Even on the darkest night
 * 			I will be your sword and shield,
 * 				Your camouflage and you will be mine
 * 	Echoes of the shots ring out
 * 		We may be the first to fall
 * 			Everything could stay the same
 * 				Or we could change it all
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
//#define double long double
typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const int inf=1e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const f80 PI = acos(-1);
struct cpx{
f80 x, y;
cpx &operator+=(const cpx &rhs){
x += rhs.x, y += rhs.y; return *this; }
cpx &operator-=(const cpx &rhs){
x -= rhs.x, y -= rhs.y; return *this; }
cpx &operator*=(const cpx &rhs){
f80 _x = x * rhs.x - y * rhs.y;
f80 _y = x * rhs.y + y * rhs.x;
x = _x,y = _y;
return *this; }
};
const int N = 5e5 + 5;
cpx roots[N];
cpx nthroot(int n){
if(roots[n].x == 0 && roots[n].y == 0)
return roots[n] = cpx{cos(2 * PI/n),sin(2 * PI/n)};
return roots[n];
}
cpx operator+(cpx lhs,const cpx &rhs) { return lhs += rhs;
}
cpx operator-(cpx lhs,const cpx &rhs) { return lhs -= rhs; }
cpx operator*(cpx lhs,const cpx &rhs) { return lhs *= rhs; }
void DFT(vector<cpx> &v,bool b = 0)
{
int n = v.size();
for(int i = 2; i <= n; i <<= 1)
{
int l = 0, r = i - 1;
cpx wn = nthroot(i);
if(b) wn.y *= (-1);
fr(j, 0, n / i - 1){
cpx w = {1, 0};
int m = l + i / 2;
fr(k, l, m - 1){
cpx t = w * v[k + i / 2];
v[k + i/2] = v[k] - t;
v[k] += t;
w *= wn;
}
l += i, r += i;
}}}
int bitrev(int r,int b){
int c = 0;
while(b--){
c <<= 1;
if(r & 1) c++;
r >>= 1;
}
return c;
}
void reorder(vector<cpx> &v,int b){
int n = v.size();
vector<cpx> temp(n);
fr(i, 0, n - 1) temp[i] = v[bitrev(i, b)];
v = temp;
}
vector<f80> polymul(vector<f80> v1,vector<f80> v2){
int inis= v1.size()+v2.size();
int n = max(v1.size(),v2.size());
v1.resize(n), v2.resize(n);
int c = 1, b = 0;
while(c < 2 * n) b++, c <<= 1;
vector<cpx> t1(c), t2(c), t3(c);
fr(i, 0, n - 1)
t1[i] = {v1[i], v2[i]};
t1.resize(c);
reorder(t1,b);
DFT(t1);
t2[0].x = t1[0].x;
t3[0].x = t1[0].y;
fr(i, 1, c - 1){
t2[i].x = (t1[i].x+t1[c-i].x)/2;
t2[i].y = (t1[i].y-t1[c-i].y)/2;
t3[i].x = (t1[i].y+t1[c-i].y)/2;
t3[i].y = (t1[c-i].x-t1[i].x)/2;
}
fr(i, 0, c - 1)
t1[i] = t2[i] * t3[i];
reorder(t1,b);
DFT(t1,1);
vector<f80> ans;
fr(i, 0, inis-2)
ans.pb(t1[i].x/c);
return ans;
}
bool gra[125001][6][6];
bool vis[125001][6];
void dfs(int j, int at) {
	vis[j][at]=1;
	for(int i=0; i<6; i++)
		if(gra[j][at][i])
			if(!vis[j][i])
				dfs(j,i);
}
void solve() {
	string s,t;
	cin>>s>>t;
	vector<f80> a(sz(s),0),b(sz(t),0);
	for(int i='a'; i<='f'; i++)
		for(int j='a'; j<='f'; j++) {
			if(i!=j) {
				for(int k=0; k<sz(s); k++)
					a[k]=(s[k]==i);
				for(int k=0; k<sz(t); k++)
					b[k]=(t[k]==j);
				reverse(all(b));
				vector<f80> res=polymul(a, b);
				for(int k=sz(t)-1; k<sz(s); k++)
					if(res[k]>0.5) {
						gra[k-sz(t)+1][i-'a'][j-'a']=1;
						gra[k-sz(t)+1][j-'a'][i-'a']=1;
					}
			}
		}
	int tel=sz(s)-sz(t)+1;
	for(int i=0; i<tel; i++) {
		int ans=6;
		for(int j=0; j<6; j++)
			if(!vis[i][j]) {
				ans--;
				dfs(i,j);
			}
		cout<<ans<<" ";
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cout<<fixed<<setprecision(10);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
/**/