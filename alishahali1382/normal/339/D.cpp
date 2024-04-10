#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int MAXN=1<<17;

int n, m, p, b, i;
int A[18][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<(1<<n); i++){
		cin>>A[17][i];
	}
	for (int j=16; j>=0; j--){
		for (int i=0; i<(1<<j); i++){
			if (j%2) A[j][i] = A[j+1][2*i] ^ A[j+1][2*i+1];
			else A[j][i] = A[j+1][2*i] | A[j+1][2*i+1];
		}
	}
	
	for (; m; m--){
		cin>>p>>b;
		A[17][--p]=b;
		for (int i=16; i>=0; i--){
			p/=2;
			if (i%2) A[i][p] = A[i+1][2*p] ^ A[i+1][2*p+1];
			else A[i][p] = A[i+1][2*p] | A[i+1][2*p+1];
		}
		cout<<A[0][0]<<endl;
	}
	
	
	
	return 0;
}