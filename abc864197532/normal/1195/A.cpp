#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int nums[1001];

int main () {
	int n,k;
	cin >> n >> k;
	int a;
	for (int i=1;i<=1000;++i) {
		nums[i]=0;
	}
	for (int i=0;i<n;++i) {
		cin >> a;
		nums[a]++;
	}
	int able=(n+1)/2,all=0;
	for (int i=1;i<=k;++i) {
		a=nums[i]/2;
		able-=a;
		all+=a*2;
	}
	cout << all+able << endl;
}