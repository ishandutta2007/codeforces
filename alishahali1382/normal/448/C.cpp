#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 100010;

int n;
int A[MAXN];

int f(int l, int r){
	if (r-l<1) return 0;
	if (r-l==1) return 1;
	
	int val=inf;
	for (int i=l; i<r; i++) val=min(val, A[i]);
	int res=val;
	int x=l;
	for (int i=l; i<r; i++){
		A[i]-=val;
		if (!A[i]){
			res+=f(x, i);
			x=i+1;
		}
	}
	//cout<<"f "<<l<<' '<<r<<' '<<min(r-l, res+f(x, r))<<endl;
	return min(r-l, res+f(x, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++)cin>>A[i];
	cout<<f(0, n)<<endl;
	return 0;
}