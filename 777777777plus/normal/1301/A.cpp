#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
string a,b,c;

int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
		int n=a.size();
		bool flag=1;
		for(int i=0;i<n;++i)
		if(a[i]!=c[i]&&b[i]!=c[i]){
			flag=0;
		}
		if(flag)puts("YES");
		else puts("NO");
	}
}