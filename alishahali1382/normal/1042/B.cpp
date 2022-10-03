#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1010;

int n, x, tmp, ans;
int A[8];
bool B[3];

string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	fill(A, A+8, inf);
	
	for (int i=0; i<n; i++){
		cin>>x>>s;
		B[0]=B[1]=B[2]=0;
		for (char ch : s) B[ch-'A']=1;
		tmp=B[0]*4+B[1]*2+B[2];
		A[tmp]=min(A[tmp], x);
		//cerr<<x<<' '<<tmp<<endl<<endl;
	}
	//cerr<<A[4]<<' '<<A[2]<<' '<<A[1]<<endl;
	for (int x : {3, 5, 7}){  // 001
		A[1]=min(A[1], A[x]);
	}
	for (int x : {3, 6, 7}){  // 010
		A[2]=min(A[2], A[x]);
	}
	for (int x : {5, 6, 7}){  // 100
		A[4]=min(A[4], A[x]);
	}
	ans=A[1]+A[2]+A[4];
	//cerr<<ans<<endl;
	ans=min(ans, A[7]);
	ans=min(ans, A[6]+A[1]);
	ans=min(ans, A[5]+A[2]);
	ans=min(ans, A[4]+A[3]);
	if (ans==inf) ans=-1;
	cout<<ans<<endl;
	return 0;
}