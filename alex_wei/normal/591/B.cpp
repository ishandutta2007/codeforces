#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
char k[26],p[26];
int n,m;
int main(){
	cin>>n>>m>>s;
	for(int i=0;i<26;i++)k[i]=i+'a';
	for(int i=0;i<m;i++){
		char x,y;
		cin>>x>>y;
		swap(k[x-'a'],k[y-'a']);
	}
	for(int i=0;i<26;i++)for(int j=0;j<26;j++)if(k[i]==j+'a')p[j]=i+'a';
	for(int i=0;i<n;i++)cout<<p[s[i]-'a'];
    return 0;
}