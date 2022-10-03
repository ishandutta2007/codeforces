#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100 * 1000 + 10;

ll n, ans;
int A[MAXN];
int B[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) cin>>B[i];
	sort(A+1, A+n+1);
	sort(B+1, B+n+1);
	int i=n, j=n;
	
	for (int turn=1; i || j; turn*=-1){
		//cout<<ans<<' '<<i<<' '<<j<<endl;
		if ((!i || A[i]<B[j]) && j){
			if (turn==1) j--;
			else ans-=B[j--]/*, cerr<<"debug"*/;
			//cerr<<"bug";
			continue ;
		}
		
		if (turn==-1) i--;
		else ans+=A[i--];
	}
	cout<<ans<<endl;
	
	return 0;
}