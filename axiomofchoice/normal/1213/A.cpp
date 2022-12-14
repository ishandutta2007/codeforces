#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	//ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int x,a[2];
	a[0]=a[1]=0;
	for(int i=0;i<n;i++){
		cin>>x;
		x%=2;
		a[x]++;
	}
	cout<<min(a[0],a[1])<<endl;
	return 0;
}