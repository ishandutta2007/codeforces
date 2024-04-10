#include<bits/stdc++.h>
using namespace std;
char s[200100];
unordered_map<int,int> pos; 
int main(){
	int S=300,T;
	scanf("%s",s);
	vector<int> v;
	int n=strlen(s);
	T=(n/S)+1;
	long long ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1') v.push_back(i);
	}
	for(int fac=1;fac<=S;fac++){
		int pre=0;
		pos.clear();
		pos[0]++;
		for(int i=0;i<n;i++){
			if(s[i]=='1') pre+=fac-1;
			else pre--;
			ans+=pos[pre];
			pos[pre]++;
		}
	}
	for(int m=1;m<=T;m++){
		for(int i=0;i+m<=v.size();i++){
			int r=i+m<v.size()?v[i+m]-1:n-1;
			for(int l=(i?v[i-1]+1:0);l<=v[i];l++){
				int min_fac=max(S+1,(v[i+m-1]-l+m)/m);
				//printf("%d %d %d\n",l,m,(r-l)/m-min_fac+1);
				ans+=max(0,(r-l+1)/m-min_fac+1);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}