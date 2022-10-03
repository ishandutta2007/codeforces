#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int f(int l, int r, int key, int A[]){
	if (r-l==1){
		return A[l]==key;
	}
	int mid=(l+r)/2;
	if (key==A[mid]){
		return true;
	}
	if (key<A[mid]){
		return f(l, mid, key, A);
	}
	return f(mid+1, r, key, A);
}

set<int> st;

int main(){
	int n, m;
	cin>>n>>m;
	int A[n];
	for (int i=0; i<n; i++){
		cin>>A[i];
		st.insert(A[i]);
	}
	sort(A, A+n);
	int ans=0;
	vector <int> out;
	for (int i=1; i<1000000; i++){
		if (m<i){
			break;
		}
		if (st.find(i)!=st.end()){//f(0, n, i, A)){
			continue;
		}
		m-=i;
		ans++;
		out.push_back(i);
	}
	cout<<ans<<endl;
	for (int i=0; i<ans; i++){
		cout<<out[i]<<' ';
	}
	cout<<endl;
	return 0;
}