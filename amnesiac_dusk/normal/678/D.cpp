/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 * 	I don't know the meaning of life
 * 		But i know what's truly precious
 * 			The way it's leading me to be in love
 * 				No fear i can find me always in my heart
 * 	The life it's not for comparing things
 * 		So i hold both of light and shadow
 * 			The rays of stars will bring me to you
 * 				Throught the dark night skies
 * 					See the way to be shined
 * 	I dont know what's right for our lives
 * 		But i know the truth of my love
 * 			The way it feels our breaths at the wind
 * 				And the way i should go all my life
 * 					I swear to go wherever will be
 * 						Thus the grace i wouldn't have
 * 							Will always in my heart
 * 								Thus the grace i wouldn't have
 * 									Will always in my heart
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
const double M_PI=acos(-1);
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
const int NN = 101;
class matrix{
public:
    ll mat[NN][NN];
    int r, c;
    matrix(){
        fr(i, 0, NN - 1)
            fr(j, 0, NN - 1)
                mat[i][j] = 0;
    }
    void setsize(int _r, int _c){ r = _r, c = _c; }
    inline matrix operator * (const matrix &a){
        assert(c == a.r);
        matrix temp;
        temp.setsize(r, a.c);
        fr(i, 0, r - 1)
            fr(j, 0, a.c - 1){
                fr(k, 0, a.r - 1){
                temp.mat[i][j] += (mat[i][k] * a.mat[k][j]) % mod;
                if(temp.mat[i][j] >= mod)
                    temp.mat[i][j] -= mod;
                }
            }
        return temp;
    }
    inline matrix operator + (const matrix &a){
        assert(r == a.r && c == a.c);
        matrix temp;
        temp.setsize(r, c);
        fr(i, 0, r - 1)
            fr(j, 0, c - 1){
                temp.mat[i][j] = mat[i][j] + a.mat[i][j] ;
                if(temp.mat[i][j] >= mod)
                    temp.mat[i][j] -= mod;
            }
        return temp;
    }
    inline matrix operator - (const matrix &a){
        assert(r == a.r && c == a.c);
        matrix temp;
        temp.setsize(r, c);
        fr(i, 0, r - 1)
            fr(j, 0, c - 1){
                temp.mat[i][j] = mat[i][j] - a.mat[i][j];
                if(temp.mat[i][j] < 0)
                    temp.mat[i][j] += mod;
            }
        return temp;
    }
    inline void operator = (const matrix &a){
        fr(i, 0, r - 1)
            fr(j, 0, c - 1)
                mat[i][j] = a.mat[i][j];
        r = a.r, c = a.c;
    }
    inline void print(){
        fr(i, 0, r - 1){
            fr(j, 0, c - 1)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
};
matrix pow(matrix a,ll k){
    assert(a.r == a.c);
    matrix ans;
    fr(i, 0, a.r - 1)
        ans.mat[i][i] = 1;
    ans.r = a.r;
    ans.c = a.r;
    while(k){
        if(k & 1)
            ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans;
}

void solve() {
	int a,b,n,x;
	cin>>a>>b>>n>>x;

	matrix ho;
	ho.setsize(2, 2);
	ho.mat[0][0]=a;
	ho.mat[1][0]=b;
	ho.mat[1][1]=1;
	matrix ans=pow(ho,n);
	cout<<(ans.mat[0][0]*x+ans.mat[1][0])%mod<<endl;
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