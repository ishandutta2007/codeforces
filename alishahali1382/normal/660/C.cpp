#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 300010;

int n, k, ans=0, s, x, ansl, ansr;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	bool f=true;
	for (int i=0; i<n; i++){
		cin>>A[i];
		if (A[i]) f=false;
		A[i]=1-A[i];
	}
	if (f){
		cout<<k<<endl;
		for (int i=0; i<k; i++) cout<<"1 ";
		for (int i=k; i<n; i++) cout<<"0 ";
		cout<<endl;
		return 0;
	}
	
	for (int i=0, j=0; i<n; i++){
		s+=A[i];
		while (s>k) s-=A[j++];
		if (i-j+1>ans){
			ans=i-j+1;
			ansl=j;
			ansr=i;
		}
	}
	for (int i=ansl; i<=ansr; i++) A[i]=0;
	cout<<ans<<endl;
	for (int i=0; i<n; i++) cout<<1-A[i]<<' ';cout<<endl;
	return 0;
}