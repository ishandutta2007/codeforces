#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
#define int ll
int n,k; string s; int b[N]; vector<int> d,rec;
int ans[N]; map<int,int> mp,mp2;
void del(int x){
	repeat(i,0,n)b[i]-=abs(x-i);
	b[x]=inf;
}
signed main(){
	int T; cin>>T;
	while(T--){
		cin>>s>>n; rec.clear(); mp.clear(); for(auto i:s)mp[i]++;
		repeat(i,0,n)cin>>b[i];
		int cnt=0;
		while(cnt<n){
			rec.push_back(0); d.clear(); 
			repeat(i,0,n)
			if(b[i]==0){
				rec.back()++;
				cnt++;
				d.push_back(i);
			}
			for(auto i:d)del(i),ans[i]=rec.size()-1;
		}
		//orzeach(rec);
		//orzarr(ans,n);
		mp2.clear();
		int p=0;
		for(auto i=mp.rbegin();i!=mp.rend();++i){
			if(i->second>=rec[p]){
				mp2[p]=i->first;
				p++;
				if(p==(int)rec.size())break;
			}
		}
		repeat(i,0,n)cout<<(char)mp2[ans[i]]; cout<<endl;
	}
	return 0;
}