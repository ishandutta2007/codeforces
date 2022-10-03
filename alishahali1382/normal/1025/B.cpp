#include <bits/stdc++.h>

using namespace std;

const int MAXN=150 * 1000 + 10;

long long n, tmp;
long long A[MAXN];
long long a[MAXN], b[MAXN];

long long gcd(long long x, long long y){
	if (y==0) return x;
	return gcd(y, x%y);
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a[i]>>b[i];
		A[i]=a[i]*b[i]/gcd(a[i], b[i]);
	}
	long long ans=A[0];
	for (int i=1; i<n; i++){
		ans=gcd(ans, A[i]);
	}
	if (ans==1){
		cout<<-1<<endl;
		return 0;
	}
	if (n==1){
		cout<<a[0]<<endl;
		return 0;
	}
	for (int i=0; i<n; i++){
		tmp=gcd(a[i], ans);
		if (tmp==1){
			ans=gcd(ans, b[i]);
		}
		else{
			ans=tmp;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}