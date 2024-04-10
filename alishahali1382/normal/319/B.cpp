#include <bits/stdc++.h>

using namespace std;

long long n, ans, inf=999999;
long long A[1000 * 1000 + 10];
long long t[1000 * 1000 + 10];
//long long cnt[1000 * 1000 + 10];
stack <long long> st;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	A[0]=inf;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		t[i]=1;
		while (!st.empty() && A[i]>A[st.top()]){
			t[i]=max(t[i], t[st.top()]+1);
			st.pop();
		}
		if (st.empty()){
			t[i]=0;
		}/*
		else{
			t[i]=max(t[i], t[st.top()]+1);
		}*/
		st.push(i);
	}
	for (int i=1; i<=n; i++){
		if (t[i]!=inf){
			//cout<<t[i]<<' ';
			ans=max(ans, t[i]);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}