#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=200005;
unordered_map<string,int> tocount;
unordered_map<string,string> example;
int n,q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n;
	while(n--) {
		string s;
		cin>>s;
		for(int l=0;l<s.length();l++) {
			string sub="";
			for(int r=l;r<s.length();r++) {
//				cout<<sub<<endl;
				sub+=s[r];
				if(example[sub]!=s) {
					example[sub]=s;
					tocount[sub]++;
				}
			}
		}
	}
	cin>>q;
	while(q--) {
		string s;
		cin>>s;
		cout<<tocount[s]<<" ";
		if(tocount[s]) cout<<example[s]<<endl;
		else cout<<"-"<<endl;
	}
	return 0;
}