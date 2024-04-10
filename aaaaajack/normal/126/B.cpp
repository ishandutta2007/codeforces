#include<bits/stdc++.h>
using namespace std;
vector<int> buildZ(const string& T){
	vector<int> Z(T.size());
	int L=0,R=0;
	for(int i=1;i<T.size();i++){
		if(i>=R) Z[i]=0;
		else Z[i]= min(Z[i-L],R-i);
		while(i+Z[i]<T.size() && T[Z[i]]==T[i+Z[i]]) Z[i]++;
		if(i+Z[i]>R) L=i,R=i+Z[i];
	}
	return Z;
}
int main(){
	string T;
	cin>>T;
	vector<int> z=buildZ(T);
	vector<int> max_suf;
	int l=-1,n=T.size(),ans=0;
	max_suf.resize(n);
	//for(int i=0;i<n;i++) printf("%d",z[i]);
	for(int i=1;i<n;i++){
		if(i+z[i]>=n) max_suf[z[i]]=z[i];
	}
	for(int i=0;i+1<n;i++){
		max_suf[i+1]=max(max_suf[i],max_suf[i+1]);
	}
	for(int i=1;i<n-1;i++){
		ans=max(ans,max_suf[min(z[i],n-i-1)]);
	}
	if(ans){
		for(int i=0;i<ans;i++) putchar(T[i]);
		puts("");
	}
	else{
		puts("Just a legend");
	}
	return 0;
}