#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

int main(){
	cin>>n>>m;
	pair<int, int> L[n];
	
	for (int i=0; i<n; i++){
		cin>>L[i].first;
		L[i].second=i;
	}
	sort(L, L+n);
	
	int out[n];
	
	for (int i=0, ans=1; i<n; i++, ans^=1){
		out[L[i].second]=ans;
	}
	for (int i=0; i<n; i++){
		cout<<out[i]<<' ';
	}
	cout<<endl;
	return 0;
}