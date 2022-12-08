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
		bool flag=1;
		for(int i=1;i<=n;++i)
		if(a[i]%2!=a[1]%2){
			flag=0;
		}
		if(flag)puts("YES");
		else puts("NO"); 
	}
}