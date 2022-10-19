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

const int N=70, mod=1e9+7, INF=1e9+5;
vector<vector<int> > V;
vi bas;
int tab[N][N];
bool ins(vector<int> V2){
	//for(int i:V2)cout<<i<<" ";
	//cout<<"\n";
	for(int i=0; i<bas.size(); i++){
		if(bas[i]!=-1 && V2[i]!=0){
			int t=(V[bas[i]][i]*V2[i])%3;
			for(int j=0; j<V2.size(); j++){
				V2[j]-=V[bas[i]][j]*t;
				V2[j]+=6;
				while(V2[j]>=3)V2[j]-=3;
			}
			assert(V2[i]==0);
		}
	}
	int f=-1;
	for(int i=0; i<bas.size(); i++){
		if(V2[i]!=0){
			f=i;
			break;
		}
	}
	//for(int i:V2)cout<<i<<" ";
	//cout<<"\n";
	//cout<<"a\n";
	if(f==bas.size()-1)return 0;
	//cout<<"b\n";
	if(f==-1)return 1;
	//cout<<"c\n";
	for(int i=0; i<bas.size(); i++){
		if(V2[i]!=0){
			assert(bas[i]==-1);
			bas[i]=V.size();
			for(int j=0; j<V.size(); j++){
				if(V[j][i]!=0){
					int t=(V[j][i]*V2[i])%3;
					for(int k=0; k<V2.size(); k++){
						V[j][k]-=V2[k]*t;
						V[j][k]+=6;
						while(V[j][k]>=3)V[j][k]-=3;
					}
					assert(V[j][i]==0);
				}
			}
			break;
		}
	}
	V.pb(V2);
	/*cout<<"d\n";
	for(int i=0; i<V.size(); i++){
		for(int j:V[i])cout<<j<<" ";
		cout<<"\n";
	}
	cout<<"dd\n";*/
	return 1;
}
int main(){
	BOOST;
	int tt=1;
	cin>>tt;
	while(tt--){
		int n, m;
		cin>>n>>m;
		vi col(m);
		for(int i=1; i<=m; i++){
			int u, v, c;
			cin>>u>>v>>c;
			if(c!=-1)tab[u][v]=tab[v][u]=-c, col[i-1]=c;
			else tab[u][v]=tab[v][u]=i;
		}
		bool b=1;
		bas.resize(m+1, -1);
		for(int i=1; i<=n; i++){
			for(int j=1; j<i; j++){
				for(int k=1; k<j; k++){
					if(tab[i][j]&&tab[j][k]&&tab[k][i]){
						//cout<<"a";
						//cout<<i<<" "<<j<<" "<<k<<"\n";
						vector<int> V2(m+1);
						if(tab[i][j]<0)V2.back()-=tab[i][j];
						else V2[tab[i][j]-1]=1;
						
						if(tab[j][k]<0)V2.back()-=tab[j][k];
						else V2[tab[j][k]-1]=1;
						
						if(tab[k][i]<0)V2.back()-=tab[k][i];
						else V2[tab[k][i]-1]=1;
						
						V2.back()%=3;
						//cout<<V2.back();
						b&=ins(V2);
					}
				}
			}
		}
		for(int i=0; i<m; i++){
			if(col[i])continue;
			vector<int> V2(m+1);
			V2[i]=1;
			for(int j=0; j<3; j++)ins(V2), V2[m]++;
		}
		for(int i=0; i<m; i++){
			if(!col[i])col[i]=(V[bas[i]][m]*V[bas[i]][i]*2)%3;
		}
		if(b==0)cout<<-1<<"\n";
		else{
			for(int i=0; i<m; i++){
				if(!col[i])col[i]+=3;
				cout<<col[i]<<" ";
			}
			cout<<"\n";
		}
		//cout<<"a\n";
		for(int i=1; i<=n; i++){
			for(int j=0; j<=n; j++){
				tab[i][j]=0;
			}
		}
		V.clear();
		bas.clear();
	}
}