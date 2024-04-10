#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <map>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> A(n);
	for (int i=0;i<n;i++){
		cin>>A[i];
	}
	map<int,int> dp;
	
	int last=0,ans=0;
	for (int i=0;i<n;i++){
		int x=A[i];
		dp[x]=dp[x-1]+1;
		if (ans<dp[x]){
			ans=dp[x];
			last=x;
		}
	}
	
	vector<int> out;
	for (int i =n-1;i>=0;i--){
		if (A[i]==last){
			out.push_back(i);
			last--;
		}
	}
	cout<<ans<<endl;
	for (int i=ans-1;i>=0;i--)
		cout<<out[i]+1<<' ';
	
	return 0;
}