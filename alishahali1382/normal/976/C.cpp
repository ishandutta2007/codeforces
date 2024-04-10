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

int main(){
	int n,l,r;
	cin>>n;
	pair<pair<int,int>,int> L[n];
	for (int i=0;i<n;i++){
		cin>>l>>r;
		L[i].first=pair<int,int>(l,r);
		L[i].second=i+1;
	}
	sort(L,L+n);
	int flag=1;
	for (int i=0;i<n-1;i++){
		int j=i+1;
		if (L[i].first.second>=L[j].first.second){
			cout<<L[j].second<<' '<<L[i].second<<endl;
			flag=0;
			//cout<<1;
			break;
		}
		else if (L[i].first.first==L[j].first.first){
			cout<<L[i].second<<' '<<L[j].second<<endl;
			flag=0;
			//cout<<2;
			break;
		}
	}
	if (flag==1){
		cout<<"-1 -1"<<endl;
	}
	
	
	return 0;
}