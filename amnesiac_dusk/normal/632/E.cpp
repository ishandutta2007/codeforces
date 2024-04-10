//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
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
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
const f80 PI = acos(-1);
struct cpx{
    f80 x, y;
    cpx &operator+=(const cpx &rhs){
        x += rhs.x, y += rhs.y;
        return *this;
    }
    cpx &operator-=(const cpx &rhs){
        x -= rhs.x, y -= rhs.y;
        return *this;
    }
    cpx &operator*=(const cpx &rhs){
        f80 _x = x * rhs.x - y * rhs.y;
        f80 _y = x * rhs.y + y * rhs.x;
        x = _x,y = _y;
        return *this;
    }
};
const int N = 2e6 + 5;
cpx roots[N];
cpx nthroot(int n){
    if(roots[n].x == 0 && roots[n].y == 0)
        return roots[n] = cpx{cos(2 * PI/n),sin(2 * PI/n)};
    return roots[n];
}
cpx operator+(cpx lhs,const cpx &rhs) { return lhs += rhs; }
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
        }
    }
}
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
    fr(i, 0, t1.size() - 1)
        ans.pb(t1[i].x/c);
    return ans;
}
int a[1005];
void solve() {
	int n,k;
	cin>>n>>k;
	vector<f80> res(1);
	res[0]=1;
	fr(i,1,n)
		cin>>a[i];
	vector<f80> curr(1001);
	fr(i,1,n) {
		curr[a[i]]=1;
	}
	while(k) {
		if(k&1) {
			res=polymul(res,curr);
			for(auto &te:res)
				if(te>1e-3)
					te=1;
				else
					te=0;
		}
		k>>=1;
		if(k) {
			curr=polymul(curr,curr);
			for(auto &te:curr)
				if(te>1e-3)
					te=1;
				else
					te=0;
		}
	}
	int ans=0;
	for(int i=0; i<res.size(); i++)
		if(res[i]>1e-3)
			cout<<i<<" ";
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}