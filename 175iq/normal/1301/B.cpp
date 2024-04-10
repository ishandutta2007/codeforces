#include <bits/stdc++.h>
using namespace std;
#define oo 1000000010
#define mod 1000000007
const int N = 300010;
int n , arr[N] ; 

void solve(){
    int mn = oo , mx = -oo;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 0;i<n;i++){
		if(i > 0 && arr[i] == -1 && arr[i - 1] != -1)
			mn = min(mn , arr[i - 1]) , mx = max(mx , arr[i - 1]);
		if(i < n - 1 && arr[i] == - 1 && arr[i + 1] != -1)
			mn = min(mn , arr[i + 1]) , mx = max(mx , arr[i + 1]);
	}
	int res = (mx + mn) / 2;
	int ans = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == -1)
			arr[i] = res;
		if(i)
			ans = max(ans,abs(arr[i] - arr[i - 1]));
	}
	printf("%d %d\n",ans,res);
}


int main(){
	int t;
	cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}