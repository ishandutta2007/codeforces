#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1010;

int n, m, tmp;
int A[MAXN];
ll B[MAXN][2];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++){
		scanf("%d", &tmp);
		A[tmp%m]++;
	}
	if (n>m){
		cout<<"YES"<<endl;
		return 0;
	}
	//for (int i=1; i<=A[1]; i++) B[i%m]++;
	B[0][0]=B[0][1]=1;
	for (int i=1; i<m; i++){
		//cerr<<A[i]<<' ';
		for (int j=0; j<m; j++){
			for (int k=1; k<=A[i]; k++){
				B[(j+i*k)%m][1]+=B[j][0];
			}
		}
		for (int j=0; j<m; j++) B[j][0]=B[j][1];
	}
	//for (int i=0; i<m; i++) cerr<<B[i][0]<<' '; cerr<<endl;
	
	if (B[0][0]>1 || A[0]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	
	return 0;
}