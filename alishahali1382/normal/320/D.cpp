#include <bits/stdc++.h>

using namespace std;

long long n, ans;
long long A[1000 * 1000 + 10];
long long t[1000 * 1000 + 10];
stack <long long> st;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		t[i]=1;
		while (!st.empty() && A[i]>A[st.top()]){
			t[i]=max(t[i], t[st.top()]+1);
			st.pop();
		}
		if (st.empty()){
			t[i]=0;
		}		st.push(i);
	}
	cout<<*max_element(t, t+n)<<endl;
	return 0;
}