#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000000;
const int mod = 998244353;
const int MAXN = 110;

int n, m;
int out[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (out[i][j]) continue ;
			//cerr<<i<<' '<<j<<endl;
			int x=0, c=4;
			if ((!i || out[i-1][j]!=1) && (!j || out[i][j-1]!=1) && out[i][j+1]!=1) c=1;
			else if ((!i || out[i-1][j]!=2) && (!j || out[i][j-1]!=2) && out[i][j+1]!=2) c=2;
			else if ((!i || out[i-1][j]!=3) && (!j || out[i][j-1]!=3) && out[i][j+1]!=3) c=3;
			if (c==1){
				while (!out[i][j+x] && (!i || out[i-1][j+x]!=1)) x++;
				//if (x==0) cerr<<"bug";
				x=min(x, min(n-i, m-j));
				//cerr<<x<<endl;
				for (int ii=0; ii<x; ii++){
					for (int jj=0; jj<x; jj++) out[ii+i][jj+j]=1;
				}
				continue ;
			}
			if (c==2){
				while (!out[i][j+x] && (!i || out[i-1][j+x]!=2) && !((!i || out[i-1][j+x]!=1)) && out[i][j+x+1]!=1 || x<1) x++;
				//if (x==0) cerr<<"bug";
				x=min(x, min(n-i, m-j));
				for (int ii=0; ii<x; ii++){
					for (int jj=0; jj<x; jj++) out[ii+i][jj+j]=2;
				}
				continue ;
			}
			out[i][j]=c;
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout<<(char) ('A'+out[i][j]-1); 
		}
		cout<<endl;
	}
	
	return 0;
}