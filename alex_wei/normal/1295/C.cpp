#include<bits/stdc++.h>
using namespace std;
int t;
vector <int> e[26];
string a,b;
int main(){
	cin>>t;
	while(t--){
		for(int i=0;i<26;i++)e[i].clear();
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			e[a[i]-'a'].push_back(i);
		}
		int ans=1,p=0;
		for(int i=0;i<b.size();i++){
			if(!e[b[i]-'a'].size()){
				ans=-1;
				break;
			}
			int x=b[i]-'a';
			int pos=lower_bound(e[x].begin(),e[x].end(),p)-e[x].begin();
			if(pos==e[x].size()){
				ans++;
				p=e[x][0];
			}
			else p=e[x][pos];
			p++;
		}
		cout<<ans<<endl;
	}
	return 0;
}