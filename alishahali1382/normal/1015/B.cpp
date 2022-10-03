#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
char s[51];
char t[51];
int cnt[26];

int main(){
	//freopen("input.txt", "r", stdin);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>s[i];
		cnt[s[i]-'a']++;
	}
	for (int i=0; i<n; i++){
		cin>>t[i];
		cnt[t[i]-'a']--;
	}
	for (int i=0; i<26; i++){
		if (cnt[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	int tmp, ans=0;
	vector<int> out;
	for (int i=0; i<n; i++){
		if (s[i]==t[i]){
			continue ;
		}
		for (int j=i+1; j<n; j++){
			if (s[j]==t[i]){
				tmp=j;
				break ;
			}
		}
		for (int j=tmp-1; j>=i; j--){
			out.push_back(j);
			ans++;
			swap(s[j], s[j+1]);
		}
	}
	cout<<ans<<endl;
	for (int i=0; i<ans; i++){
		cout<<out[i]+1<<' ';
	}
	
	cout<<endl;
	return 0;
}