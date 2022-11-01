# include <bits/stdc++.h>

using namespace std;

int dlr[7] = {1,2,5,10,20,50,100};
int ers[6] = {5,10,20,50,100,200};

int main(){
	long long int n, d, e;
	cin >> n >> d >> e;
	long long ans = 1e18;
	//for (long long i=0; i<n; i++){
		for (long long j=0; j<=n; j+=d) if ((n-j)%(e*5) < ans) ans = (n-j)%(e*5);
	//}
	cout << ans;
}