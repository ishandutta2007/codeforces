#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
int main(){
	set<int> S[26];
	int q,n,l,r,no;
	char arr[100005],a,b;
	cin>>arr;
	for(int i = 0;arr[i];i++){
		S[arr[i]-'a'].insert(i);
	}
	cin>>q;
	while(q--){
		cin>>no;
		//cout<<no;
		if(no == 1){
			cin>>n>>a;
			S[arr[n-1]-'a'].erase(n-1);
			S[a-'a'].insert(n-1);
			arr[n-1] = a;
		}
		else{
			int ct = 0;
			cin>>l>>r;
			for(int i = 0; i<26; i++){
				auto it1 = S[i].lower_bound(l-1);
				//cout<<*it1<<"IT\n";
				if(it1 != S[i].end() && *it1 <= r-1) ct++;
			}
			cout<<ct<<endl;
		}
	}
}