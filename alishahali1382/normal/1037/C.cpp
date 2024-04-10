#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=1000 * 1000 + 10;

int n, s, ans, m;

char a[MAXN], tmp;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) cin>>a[i];
	for (int i=0; i<n; i++){
		cin>>tmp;
		A[i]=a[i]==tmp;
	}
	for (int i=0; i<n; i++){
		if (A[i]) continue ;
		ans++;
		if (i<n-1 && !A[i+1] && a[i+1]!=a[i]){
			i++;	
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}