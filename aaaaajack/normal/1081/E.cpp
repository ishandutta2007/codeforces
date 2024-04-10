#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<long long> tmp,x;
	x.resize(n/2);
	bool gg=false;
	for(int i=0;i<n/2;i++){
		cin>>x[i];
		if(x[i]%4==2){
			gg=true;
		}
		if(gg) continue;
		long long pre=round(sqrt(i?x[i-1]+tmp[i-1]*tmp[i-1]:0))+1;
		long long st=2-(x[i]&1);
		if(x[i]/st-st<pre*2){
			gg=true;
			continue;
		}
		for(long long j=st;x[i]/j-j>=pre*2;j+=2){
			if(x[i]%j==0 && (x[i]/j-j)%2==0) st=j;
		}
		tmp.push_back((x[i]/st-st)/2);
	}
	if(gg) puts("No");
	else{
		vector<long long> ans;
		for(int i=0;i<n/2;i++){
			ans.push_back(tmp[i]*tmp[i]);
			ans.push_back(ans.back()+x[i]);
		}
		for(int i=n-1;i>0;i--){
			ans[i]-=ans[i-1];
			if(ans[i]<=0) gg=true;
		}
		if(gg) puts("No");
		else{
			puts("Yes");
			for(int i=0;i<n;i++){
				cout<<ans[i]<<' ';
			}
		}
	}
	return 0;
}