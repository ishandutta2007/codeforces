#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int s, limit, tmp;

int lowbit(int x){
	return 1<<(__builtin_ctz(x));
}

int main(){
	//freopen("input.txt", "r", stdin);
	cin>>s>>limit;
	vector<int> ans;
	for (int i=limit; i>0; i--){
		tmp=lowbit(i);
		if (s>=tmp){
			s-=tmp;
			ans.push_back(i);
		}
		if (!s) break ;
	}
	if (s){
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans.size()<<endl;
	for (int i=0; i<ans.size(); i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}