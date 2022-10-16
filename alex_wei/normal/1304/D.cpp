#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>

int t,n;
string s;
void a(){
	int rem=n;
	s+='>';
	for(int i=0;i<s.size();i++){
		if(s[i]=='>'){
			cout<<rem--<<" ";
			continue;
		}
		int cnt=0;
		while(i+cnt<s.size()&&s[i+cnt]=='<')cnt++; 
		for(int j=rem-cnt;j<=rem;j++)cout<<j<<" ";
		rem-=cnt+1;
		i=i+cnt;
	}
	cout<<endl;
}
void b(){
	int rem=1;
	s=s.substr(0,n-1);
	s+='<';
	for(int i=0;i<s.size();i++){
		if(s[i]=='<'){
			cout<<rem++<<" ";
			continue;
		}
		int cnt=0;
		while(i+cnt<s.size()&&s[i+cnt]=='>')cnt++; 
		for(int j=rem+cnt;j>=rem;j--)cout<<j<<" ";
		rem+=cnt+1;
		i=i+cnt;
	}
	cout<<endl;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		a(),b();
	}
    return 0;
}