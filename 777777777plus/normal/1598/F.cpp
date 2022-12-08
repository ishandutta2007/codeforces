#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 8e5+5;
const int B = 4e5;

int n;
string s[20];
vector<int> cnt[20][N];
vector<int> mn[20];
int f[1<<20],t[20];

int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s[i];
		int mnn=2e9;
		for(int j=0;j<s[i].size();++j){
			if(s[i][j]=='(')++t[i];
			else --t[i];
			mnn=min(mnn,t[i]);
			mn[i].push_back(mnn);
			cnt[i][t[i]+B].push_back(j);
		}
	}
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	int ans=0;
	for(int i=0;i<(1<<n);++i){
		int tot=0;
		for(int j=0;j<n;++j)if(i&1<<j)tot+=t[j];
		ans=max(ans,f[i]);
		for(int j=0;j<n;++j)
		if(!(i&1<<j)){
			if(tot+mn[j].back()>=0){
				f[i|1<<j]=max(f[i|1<<j],(int)cnt[j][-tot+B].size()+f[i]);
			}
			else{
				int l=0,r=mn[j].size()-1;
				while(l!=r){
					int mid=l+r>>1;
					if(mn[j][mid]<-tot)r=mid;
					else l=mid+1;
				}
				int p=upper_bound(cnt[j][-tot+B].begin(),cnt[j][-tot+B].end(),l)-cnt[j][-tot+B].begin()-1;
				ans=max(ans,f[i]+p+1);
			}
		}
	}
	cout<<ans<<endl;
}