#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll b=131,bb=37,m1=1e9+7,m2=998244353;
const int N=1e6+2;
ll po[N],po2[N];
int n;
string s[12];
int main()
{
	cin>>n>>s[1];
	po[0]=po2[0]=1;
	for(int i=1;i<=1e6;i++)po[i]=po[i-1]*b%m1,po2[i]=po2[i-1]*bb%m2;
	cout<<s[1];
	for(int i=2;i<=n;i++){
		cin>>s[2];
		ll a1=0,b1=0,a2=0,b2=0;
		int temp=0;
		for(int j=0;j<min(s[2].size(),s[1].size());j++){
			a1=(a1+s[1][s[1].size()-j-1]*po[j])%m1,a2=(a2+s[1][s[1].size()-j-1]*po2[j])%m2;
			b1=(b1*b+s[2][j])%m1,b2=(b2*bb+s[2][j])%m2;
			if(a1==b1&&a2==b2)temp=j+1;
		}
		for(int j=temp;j<s[2].size();j++)
			cout<<s[2][j],s[1]+=s[2][j];
	}
	return 0;
}