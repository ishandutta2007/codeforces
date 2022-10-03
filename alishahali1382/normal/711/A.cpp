#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1000 + 10;

int n, tmp;
string A[MAXN];

void print(){
	cout<<"YES"<<endl;
	for (int i=0; i<n; i++) cout<<A[i]<<endl;
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<n; i++){
		if (A[i][0]==A[i][1] && A[i][1]=='O'){
			A[i][0]=A[i][1]='+';
			print();
			return 0;
		}
		if (A[i][3]==A[i][4] && A[i][4]=='O'){
			A[i][3]=A[i][4]='+';
			print();
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}