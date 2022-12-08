#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		bool flag=0;
		for(int i=1;i<=n;++i)
		for(int j=i+2;j<=n;++j)
		if(a[i]==a[j]){
			flag=1;
		}
		if(flag)puts("YES");
		else puts("NO");
	}
}