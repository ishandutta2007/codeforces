#include<bits/stdc++.h>
using namespace std;
int T,cnt[2][300003];
int n;string s;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		for(int i=0;i<=n;i++)cnt[0][i]=0,cnt[1][i]=0;
		for(int i=1;i<=n;i++)
			if(s[i-1]=='L')
				if(i-1&&s[i-2]=='R')
					cnt[0][i]=cnt[0][i-2]+2;
				else
					cnt[0][i]=1;
			else
				cnt[0][i]=0;
		for(int i=n-1;i>=0;i--)
			if(s[i]=='R')
				if(i+1<n&&s[i+1]=='L')
					cnt[1][i]=cnt[1][i+2]+2;
				else
					cnt[1][i]=1;
			else
				cnt[1][i]=0;
		for(int i=0;i<=n;i++)printf("%d ",cnt[1][i]+cnt[0][i]+1);cout<<endl;
	}
}