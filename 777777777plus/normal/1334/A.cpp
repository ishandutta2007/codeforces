#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n;
int p[N],c[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		bool flag=1;
		for(int i=1;i<=n;++i){
			cin>>p[i]>>c[i];
			if(p[i]<p[i-1]||c[i]<c[i-1])flag=0;
			if(p[i]-p[i-1]<c[i]-c[i-1])flag=0;
		}
		if(flag)puts("YES");
		else puts("NO");
	}
}