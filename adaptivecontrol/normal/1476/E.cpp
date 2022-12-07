#include<bits/stdc++.h>
using namespace std;
int n,m,k,mt;
vector<int>v[100003];
string s[100003],t,tmp;
map<string,int>mp;
int cnt[100003];
queue<int>Q;
vector<int>ans;
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>s[i];
		mp[s[i]]=i+1;
	}
	for(int i=0;i<m;i++){
		cin>>t>>mt;mt--;
		bool ok=0;
		for(int j=0;j<(1<<k);j++){
			tmp=t;
			for(int l=0;l<k;l++)
				if((1<<l)&j)
					tmp[l]='_';
			if(mp[tmp])
				if(mt!=mp[tmp]-1){
					v[mt].push_back(mp[tmp]-1);
					cnt[mp[tmp]-1]++;
//					cout<<mt<<' '<<mp[tmp]-1<<endl;
				}
				else ok=1;else;
		}
		if(!ok){cout<<"NO";return 0;}
	}
	for(int i=0;i<n;i++)
		if(cnt[i]==0){
			ans.push_back(i+1);
			Q.push(i);
		}
//	for(int i=0;i<n;i++)cout<<cnt[i]<<' ';cout<<endl;
	while(Q.size()){
		int nw=Q.front();Q.pop();
		for(int i=0;i<v[nw].size();i++){
			cnt[v[nw][i]]--;
			if(!cnt[v[nw][i]]){
				Q.push(v[nw][i]);
				ans.push_back(v[nw][i]+1);
			}
		}
	}
	if(ans.size()<n){cout<<"NO";return 0;}
	cout<<"YES\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
}