#include<bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("trapv")

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

template <typename H, typename T> 
ostream& operator<<(ostream& os, pair<H, T> m){
	return os <<"("<< m.st<<", "<<m.nd<<")";
}
template <typename H> 
ostream& operator<<(ostream& os, vector<H> V){
	os<<"{";
	for(int i=0; i<V.size(); i++){
		if(i)os<<" ";
		os<<V[i];
	}
	os<<"}";
	return os;
}

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=2e3, M=N*N, INF=1e9+5, mod=1e9+7;
int czy[M];
bool dobre(ll x){
	if(x<M){
		return czy[x];
	}
	int i=floor(sqrt(x));
	return x<=i*ll(i)+i;
}
int main(){
	BOOST;
	for(int i=1; i<N; i++){
		for(int j=0; j<=i; j++){
			czy[i*i+j]=1;
		}
	}
	//for(int i=1; i<10; i++)cout<<czy[i];
	int n;
	cin>>n;
	vector<int> V(n);
	for(int &i:V)cin>>i;
	/*shuffle(all(V), rng);
	for(int i=0; i<M/2; i++){
		bool b=1;
		for(int j:V){
			//cout<<j+i<<" ";
			if(!czy[j+i]){
				b=0;
				break;
			}
		}
		if(b){
			cout<<i;
			return 0;
		}
	}*/
	sor(V);
	vector<pii> V2;
	for(int i:V)V2.pb(mp(i, i));
	for(int i=1; ;i++){
		//deb(i);
		if(i*ll(i)+i<V[0])continue;
		vector<pii> V3;
		for(int j=0; j<V2.size(); j++){
			if(!j || V2[j].st>V3.back().nd+i){
				V3.pb(V2[j]);
			}
			else{
				V3.back().nd=V2[j].nd;
			}
		}
		V2=V3;
		V3.clear();
		ll md=i*ll(i)-V[0], Md=md+i;
		md=max(md, 0ll);
		for(int j=0; j<V2.size(); j++){
			int k=floor(sqrt(V2[j].st+Md));
			//if(k*ll(k)<=V2[j].st+Md)k++;
			//deb(k, V2[j]);
			md=max(k*ll(k)-V2[j].st, md);
			Md=min(Md, k*ll(k)+k-V2[j].nd);
			//deb(md, Md);
			if(Md<md)break;
		}
		if(Md>=md){
			//deb(md, Md, i);
			//for(auto j:V2)
				//deb(j);
			cout<<md<<"\n";
			return 0;
		}
	}
}