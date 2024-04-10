#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 510;

ll n, x, y;
ll A[MAXN][MAXN];
ll sum1[MAXN];
ll sum2[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	if (n==1){
		cout<<1<<endl;
		return 0;
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin>>A[i][j];
			sum1[i]+=A[i][j];
			if (!A[i][j]){
				x=i;
				y=j;
			}
		}
	}
	ll xx=(x+1)%n, yy=(y+1)%n, s=0, ss=0;
	A[x][y]=sum1[xx]-sum1[x];
	sum1[x]=sum1[xx];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			sum2[j]+=A[i][j];
		}
	}
	for (int i=0; i<n; i++){
		s+=A[i][i];
		ss+=A[i][n-i-1];
	}
	if (s!=ss || A[x][y]<=0){
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0; i<n; i++){
		if (sum1[i]!=s || sum2[i]!=s){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<A[x][y]<<endl;
	
	
	return 0;
}