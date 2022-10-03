#include <bits/stdc++.h>

using namespace std;

const int MAXN=1000 * 1000 + 10;

int n, m, q, l, r;
int A[26];
char ch;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	if (n==1){
		cout<<"Yes"<<endl;
		return 0;
	}
	for (int i=0; i<n; i++){
		cin>>ch;
		A[ch-'a']++;
	}
	for (int i=0; i<26; i++){
		if (A[i]>1){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}