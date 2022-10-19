#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=1e5+5, K=18, mod=998244353, INF=1e9+5;
ll dp[K][N];
int sito[N], phi[N];
ll sum[N];
//map<pair<int, int>, ll> M;
/*const int A=350;
ll koszt[A][N];
vector<pair<int, ll> > val[N]; 
ll Cost(int l, int r){
	/*if(M.find(mp(l, r))!=M.end())return M[mp(l, r)];
	int L=l, R=r;
	ll ans=0;
	while(r>=l*1ll*l){
		ans+=sum[r/l];
		l++;
	}
	//cout<<ans<<" "<<l<<" "<<r<<" ";
	int k=r/l;
	for(; k>=1; k--){
		int m=r/k;
		ans+=(m-l+1)*1ll*sum[k];
		l=m+1;
	}
	M[mp(L, R)]=ans;
	return ans;
	if(val[r].back().st>=l)return koszt[l][r];
	int L=0, R=val[r].size()-1;
	while(L<R){
		int M=(L+R)>>1;
		if(val[r][M].st>=l)L=M+1;
		else R=M;
	}
	return val[r][L].nd+(val[r][L].st-l)*sum[L+1];
}*/
ll Cost(int l, int r){
	ll ans=0;
	while(r>=l*1ll*l){
		ans+=sum[r/l];
		l++;
	}
	//cout<<ans<<" "<<l<<" "<<r<<" ";
	int k=r/l;
	for(; k>=1; k--){
		int m=r/k;
		ans+=(m-l+1)*sum[k];
		l=m+1;
	}
	return ans;
}
/*ll cost(int l, int r){
	int ans=0;
	for(int i=l; i<=r; i++){
		for(int j=i; j<=r; j++){
			ans+=(__gcd(i, j)>=l);
		}
	}
	return ans;
}*/
int n;
ll cost2(int l, int r){
	return Cost(n+1-r, n+1-l);
}
void prop(int l, int r, int a ,int b, int k){
    int m=(l+r)/2, skad=m;
    dp[k][m]=dp[k-1][m];
    ll C=Cost(a, m);
    for(int i=a; i<=b && i<m; i++){
        C-=sum[m/i];
        //M[mp(i+1, m)]=C;
        if(dp[k-1][i]+C<dp[k][m]){
            skad=i;
            dp[k][m]=dp[k-1][i]+C;
        }
    }
    if(m>l)prop(l, m-1, a, skad, k);
    if(m<r)prop(m+1, r, skad, b, k);
}
int main(){
	BOOST;
	sum[1]=1;
	for(int i=2; i<N; i++){
		if(sito[i]==0){
			for(int j=1; j*i<N; j++){
				sito[j*i]=i;
			}
		}
		phi[i]=1;
		int k=i;
		while(k>1){
			int p=sito[k];
			phi[i]*=p-1;
			k/=p;
			while(k%p==0){
				k/=p;
				phi[i]*=p;
			}
		}
		sum[i]=sum[i-1]+phi[i];
	}
	/*for(int i=1; i<N; i++){
		val[i].push_back(mp(i, 1));
		for(int k=2; val[i].back().st>=A; k++){
			val[i].push_back(mp(i/k, (val[i].back().st-(i/k)-1)*1ll*sum[k]+sum[k+1]+val[i].back().nd));
		}
		koszt[val[i].back().st][i]=val[i].back().nd;
		for(int j=val[i].back().st-1; j>0; j--){
			koszt[j][i]=koszt[j+1][i]+sum[i/j];
		}
	}*/
	//cout<<Cost(1, 4);
	/*for(int i=1; i<=10; i++){
		cout<<phi[i]<<" "<<sum[i]<<" ";
		for(int j=1; j<=i; j++){
			cout<<cost(j, i)<<"|"<<Cost(j, i)<<" ";
		}
		cout<<"\n";
	}*/
	for(int i=1; i<N; i++){
		dp[0][i]=Cost(1, i);
   	}
   	for(int i=1; i<K; i++){
		prop(1, N-1, 1, N-1, i);
    }
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>n>>k;
		//n=1e5, k=15;
		if(k>=K || (1<<k)>n)cout<<n<<"\n";
		else{
			
    		cout<<dp[k-1][n]<<"\n";
		}
	}
}