#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=200 * 1000 + 10;

ll n, ans=1, cur=1;
ll A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
	}
	for (int i=1; i<n; i++){
		if (A[i]>2*A[i-1]){
			ans=max(ans, cur);
			cur=1;
			continue ;
		}
		ans=max(ans, ++cur);
	}
	cout<<ans<<endl;
	
	return 0;
}