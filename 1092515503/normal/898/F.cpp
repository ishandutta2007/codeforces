#include<bits/stdc++.h>
using namespace std;
const int m1=19260817,m2=666623333;
int n,p1[1001000],p2[1001000];
pair<int,int>hs[1001000];
char s[1001000];
pair<int,int>gt(int l,int r){
	return make_pair((hs[r].first-(1ll*hs[l].first*p1[r-l]%m1)+m1)%m1,(hs[r].second-(1ll*hs[l].second*p2[r-l]%m2)+m2)%m2);
}
pair<int,int>operator +(const pair<int,int>&x,const pair<int,int>&y){
	return make_pair((x.first+y.first)%m1,(x.second+y.second)%m2);
}
int main(){
	scanf("%s",s+1),n=strlen(s+1),p1[0]=p2[0]=1;
	for(int i=1;i<=n;i++)p1[i]=(10ll*p1[i-1])%m1,p2[i]=(10ll*p2[i-1])%m2;
	for(int i=1;i<=n;i++)hs[i]=make_pair((10ll*hs[i-1].first+(s[i]-'0'))%m1,(10ll*hs[i-1].second+(s[i]-'0'))%m2);
	for(int i=1;i<=n/2;i++){
		for(int j=max(i+1,n-i-1);j<=min(n-1,n-i);j++){
			if(hs[i]+gt(i,j)!=gt(j,n))continue;
			if(s[1]=='0'&&i>=2)continue;
			if(s[i+1]=='0'&&j-i>=2)continue;
			if(s[j+1]=='0'&&n-j>=2)continue;
			for(int k=1;k<=i;k++)printf("%c",s[k]);
			putchar('+');
			for(int k=i+1;k<=j;k++)printf("%c",s[k]);
			putchar('=');
			for(int k=j+1;k<=n;k++)printf("%c",s[k]);
			putchar('\n');
			return 0;
		}
		for(int j=max(i+1,i+(n-i)/2-2);j<=min(n-1,i+(n-i)/2+2);j++){
			if(hs[i]+gt(i,j)!=gt(j,n))continue;
			if(s[1]=='0'&&i>=2)continue;
			if(s[i+1]=='0'&&j-i>=2)continue;
			if(s[j+1]=='0'&&n-j>=2)continue;
			for(int k=1;k<=i;k++)printf("%c",s[k]);
			putchar('+');
			for(int k=i+1;k<=j;k++)printf("%c",s[k]);
			putchar('=');
			for(int k=j+1;k<=n;k++)printf("%c",s[k]);
			putchar('\n');
			return 0;
		}		
	}
	return 0;
}