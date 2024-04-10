#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1000 * 1000 + 10;

int n, k, ans;
int A[26];

string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	cin>>s;
	for (int i=0; i<n; i++){
		A[s[i]-'A']++;
	}
	cout<<*min_element(A, A+k)*k<<endl;
	
	return 0;
}