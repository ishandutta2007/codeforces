#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int MAXN=5010;

int n, x, a, b, c;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>x;
		a+=x;
	}
	for (int i=0; i<n-1; i++){
		cin>>x;
		b+=x;
	}
	for (int i=0; i<n-2; i++){
		cin>>x;
		c+=x;
	}
	cout<<a-b<<endl;
	cout<<b-c<<endl;
	
	
	return 0;
}