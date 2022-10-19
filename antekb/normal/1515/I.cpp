#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

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

//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const ll INF=2e18;
const int K=19, N=1<<K, mod=1e9+7;
int wei[N], imp[N], gdzie[N], lev[N];
ll ile[N];
ll sum[K][N+N];//suma wag z przedzialu waznosci [0, 2^k)
ll sum2[K][N+N];//suma waznosci
ll tab[K][N+N];// sum + wei[k][i], ktore jest wei[i] lub INF do brania zachlannie
ll lazy[K][N+N];
int n;
ll ans;
int dep, s;
ll C;
void prop(int k, int v){
	if(v>=N || !lazy[k][v])return;
	int l=2*v, r=l+1;
	//deb(k, v);
	lazy[k][l]+=lazy[k][v];
	lazy[k][r]+=lazy[k][v];
	tab[k][l]+=lazy[k][v];
	tab[k][r]+=lazy[k][v];
	lazy[k][v]=0;
}
void add(int k, int v, int L, int R, int l, int r, ll c){
	//deb(k, v, L, R, l, r, c);
	if(L==l && r==R){
		lazy[k][v]+=c;
		tab[k][v]+=c;
		return;
	}
	int M=(L+R)>>1;
	prop(k, v);
	if(l<=M)add(k, 2*v, L, M, l, min(M, r), c);
	if(r>M)add(k, 2*v+1, M+1, R, max(l, M+1), r, c);
	tab[k][v]=min(tab[k][2*v], tab[k][2*v+1]);
	return;
}
void add2(int k, int v, int L, int R, int l, int r, ll c){
	//deb(k, v, L, R, l, r, c);
	if(L==l && r==R){
		for(int j=k; j<K; j++)lazy[j][v]+=c;
		for(int j=k; j<K; j++)tab[j][v]+=c;
		return;
	}
	int M=(L+R)>>1;
	for(int j=k; j<K; j++)prop(j, v);
	if(l<=M)add2(k, 2*v, L, M, l, min(M, r), c);
	if(r>M)add2(k, 2*v+1, M+1, R, max(l, M+1), r, c);
	for(int j=k; j<K; j++)tab[j][v]=min(tab[j][2*v], tab[j][2*v+1]);
	return;
}
void update(int i, int c){
	//deb(c*1ll*wei[i]);
	if(!ile[i]){
		add(lev[i], 1, 0, N-1, i, i, wei[i]-INF);
		//deb(lev[i], tab[1][lev[i]]);
	}
	ile[i]+=c;
	if(!ile[i]){
		add(lev[i], 1, 0, N-1, i, i, INF-wei[i]);
	}
	for(int j=lev[i]+1; j<K; j++){
			for(int l=N+i; l; l>>=1){
				sum2[j][l]+=c*1ll*imp[i];
				sum[j][l]+=c*1ll*wei[i];
			}
		}
	add2(lev[i]+1, 1, 0, N-1, i, n-1, c*1ll*wei[i]);
}
void small(){
	int t=s+N;
	//deb(s, C);
	while(t>1){
		if(t&1){
			C+=sum[dep+1][t-1];
			ans-=sum2[dep+1][t-1];
		}
		t/=2;
	}
	//deb(C);
	while(t<N){
		if(sum[dep+1][2*t]<=C){
			C-=sum[dep+1][2*t];
			ans+=sum2[dep+1][2*t];
			t=2*t+1;
		}
		else t=2*t;
	}
	s=t-N;
	//deb(s, C, ans);
	if(s<n){
		ll a=C/wei[s];
		C-=wei[s]*a;
		ans+=imp[s]*a;
	}
}
void prop_up(int v){
	if(v!=1)prop_up(v/2);
	prop(dep, v);
}
void big(){
	//assert(wei[s]>C);
	//assert(ile[s]);
	int t=s+N;
	prop_up(t);
	//assert(tab[dep][t]>C);
	//deb(ans, C);
	t++;
	while(t>1){
		if(t&1){
			C+=sum[dep][t-1];
			ans-=sum2[dep][t-1];
		}
		t/=2;
	}
	t=s+N;
	//if(dep==4)deb(ans, C);
	while(t>1){
		if(dep==3){
			//deb(ans, C, t, tab[dep][t+1]);	
		}
		//assert(!lazy[dep][t/2]);
		if(!(t&1) && tab[dep][t+1]<=C){
			//deb("a");
			t++;
			while(t<N){
				prop(dep, t);
				if(tab[dep][2*t]<=C){
					t=2*t;
				}
				else t=2*t+1;
			}
			break;
		}
		t/=2;
	}
	//deb("a", s);
	if(t==1){
		t=s+N+1;
		while(t>1){
			if(t&1){
				C-=sum[dep][t-1];
				ans+=sum2[dep][t-1];
			}
			t/=2;
		}
		//deb(ans, C);
		dep--;
		return;
	}
	//cerr<<"a\n";
	s=t-N;
	//deb(s, ans, C);
	while(t>1){
		if(t&1){
			C-=sum[dep][t-1];
			ans+=sum2[dep][t-1];
		}
		t/=2;
	}
	//deb(s, ans, C);
	C-=wei[s];
	ans+=imp[s];
	dep--;
}
int main(){
	BOOST;
	int q;
	cin>>n>>q;
	vector<pair<pii, pii> > V(n);
	for(int i=0; i<V.size(); i++){
		cin>>V[i].nd.st>>V[i].st.nd>>V[i].st.st;
		V[i].nd.nd=i+1;
		V[i].st.nd*=-1;
	}
	sor(V);
	rev(V);
	for(int j=0; j<K; j++){
		add(j, 1, 0, N-1, 0, N-1, INF);
		int v=N+n;
		while(v){
			sum[j][v]+=INF;
			v/=2;
		}
	}
	for(int i=0; i<n; i++){
		wei[i]=-V[i].st.nd;
		for(int j=0; j<K; j++)if(wei[i]<(1<<j)){
			lev[i]=j;
			//deb(i, lev[i]);
			break;
		}
		gdzie[V[i].nd.nd]=i;
		imp[i]=V[i].st.st;
		update(i, V[i].nd.st);
		
	}
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int k, d;
			cin>>k>>d;
			update(gdzie[d], k);
		}
		if(t==2){
			int k, d;
			cin>>k>>d;
			update(gdzie[d], -k);
		}
		if(t==3){
			cin>>C;
			s=0;
			ans=0;
			dep=K-2;
			while(s<n && dep>0){
				while(2*C+1<(1<<(dep)))dep--;
				if(dep==0)break;
				small();
				//deb(s, C, ans, dep)				
				big();
				//deb(s, C, ans, dep)
			}
			cout<<ans<<"\n";
		}
	}
}