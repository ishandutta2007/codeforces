#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s;
ll ans,pre[100005],sum;
int main(){
	cin>>s;
	for(int i=0;i<26;i++){
		sum=0;
		for(int j=0;j<s.size();j++)sum+=s[j]==i+'a';
		ans=max(ans,sum);
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			memset(pre,0,sizeof(pre));
			ll cnt=0;
			for(int k=1;k<=s.size();k++)pre[k]=pre[k-1]+(s[k-1]==i+'a');
			for(int k=1;k<=s.size();k++)if(s[k-1]==j+'a')cnt+=pre[k]-(i==j);
			ans=max(ans,cnt);
		}
	}
	cout<<ans<<endl;
    return 0;
}