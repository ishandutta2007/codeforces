#include<bits/stdc++.h>
using namespace std;
map <pair<int,int> ,int> mp;
int t,n;
string s; 
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		int x=0,y=0,ansl=0,ansr=n;
		mp.clear();
		mp[{0,0}]=1;
		for(int i=2;i<=s.size()+1;i++){
			if(s[i-2]=='L')x--;
			else if(s[i-2]=='R')x++;
			else if(s[i-2]=='U')y++;
			else if(s[i-2]=='D')y--;
			int k=mp[{x,y}];
			if(k!=0&&ansr-ansl>i-k-1)ansl=k+1,ansr=i;
			mp[{x,y}]=i;
		}
		if(!ansl)puts("-1");
		else cout<<ansl-1<<" "<<ansr-1<<endl;
	}
    return 0;
}