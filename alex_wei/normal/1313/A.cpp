#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
int a,b,c;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
		int ans=0;
		if(a)a--,ans++;
		if(b)b--,ans++;
		if(c)c--,ans++;
		if(a<b)swap(a,b);
		if(b<c)swap(b,c);
		if(a<b)swap(a,b);
		if(a&&b)a--,b--,ans++;
		if(b&&c)b--,c--,ans++;
		if(a&&c)a--,c--,ans++;
		if(a&&b&&c)ans++;
		cout<<ans<<endl;
	}
	return 0;
}