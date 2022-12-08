#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15;

int T;
int s,n,b[N],cnt[N];
vector<int> ans;

void output(){
	ans.clear();
	for(int i=0;i<=9;++i)
	for(int j=1;j<=cnt[i];++j)
	ans.push_back(b[i]);
	for(int i=n;i<ans.size();++i)ans[n-1]+=ans[i];
	for(int i=0;i<n;++i)cout<<ans[i]<<" ";
	cout<<endl;
} 

int main(){
	b[0]=1;
	for(int i=1;i<=9;++i)b[i]=b[i-1]*10;
	cin>>T;
	while(T--){
		cin>>s>>n;
		int tot=0;
		for(int i=0;i<=9;++i){
			int c=(s/b[i])%10;
			cnt[i]=c;
			tot+=c;
		}
		if(tot>=n){
			output();
			continue;
		}
		while(tot<n){
			vector<int> nex;
			for(int i=1;i<=9;++i)
			if(cnt[i]){
				--cnt[i];
				cnt[i-1]+=10;
				tot+=9;
				break;
			}
		}
		output();
	}
}