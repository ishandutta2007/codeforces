#include<bits/stdc++.h>
using namespace std;
int main(){
	string T;
	cin>>T;
	vector<int> f;
	vector<int> cnt;
	vector<int> ans;
	int l=-1,n=T.size();
	f.resize(n);
	cnt.resize(n,1);
	f[0]=-1;
	for(int i=1; i<T.size();i++){
		while(T[i]!=T[l+1] && l>=0) l=f[l];
		if(T[i]==T[l+1]) l=l+1;
		f[i] = l;
	}
	for(int i=n-1;i>=0;i=f[i]){
		ans.push_back(i);
	}
	for(int i=n-1;i>=0;i--){
		if(f[i]>=0){
			cnt[f[i]]+=cnt[i];
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i=ans.size()-1;i>=0;i--){
		printf("%d %d\n",ans[i]+1,cnt[ans[i]]);
	}
	return 0;
}