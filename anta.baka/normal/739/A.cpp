#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin>>n>>m;
	int len=(int)1e8;
	for(int i=0; i<m; i++){
		int l,r;
		cin>>l>>r;
		len=min(len,r-l+1);
	}
	cout<<len<<"\n";
	for(int i=0; i<n; i++)
		cout<<i%len<<' ';
}