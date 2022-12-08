#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,a[N],b[N];
string s;

int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		int ans1=0,ans2=0;
		for(int i=0;i<n;++i)
		if(s[i]-'0'!=(i&1))b[i]=1;
		else b[i]=0;
		for(int i=0;i<n;++i)
		if(((s[i]-'0')^1)!=(i&1))a[i]=1;
		else a[i]=0;
		for(int i=0;i<n;++i)
		if(i&&a[i]==a[i-1]&&a[i]==1)continue;
		else if(a[i]==1)ans1++;
		for(int i=0;i<n;++i)
		if(i&&b[i]==b[i-1]&&b[i]==1)continue;
		else if(b[i]==1)ans2++;
		cout<<min(ans1,ans2)<<endl;
	}
}