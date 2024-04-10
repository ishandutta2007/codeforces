#include<bits/stdc++.h>
using namespace std;
char s[1100],t[1100];
int cnt[30];
bool a[1100];
int u[30];
int main(){
	int _;
	cin>>_;
	while(_--){
		scanf("%s%s",s+1,t+1);
		int n=strlen(s+1);
		int m=strlen(t+1);
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=0;i<30;i++)cnt[i]=0;
		for(int i=1;i<=m;i++)cnt[t[i]-'A']++;
		for(int i=0;i<30;i++)u[i]=0;
		for(int i=n;i>=1;i--){
			u[s[i]-'A']++;
			if(u[s[i]-'A']<=cnt[s[i]-'A'])a[i]=1;
		}
		bool r=1;
		for(int i=0;i<30;i++)if(u[i]<cnt[i])r=0;
		if(r==0){
			cout<<"NO\n";
			continue;
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			if(a[i]){
				if(s[i]!=t[++tot])r=0; 
			}
		}
		if(r==0)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}