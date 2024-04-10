#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,x;
int a[N],b[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>x;
		for(int i=1;i<=n;++i)cin>>a[i];
		bool flag=0;
		for(int i=1;i<=n;++i){
			b[i]=b[i-1]+a[i];
			if(b[i]==x){
				if(i==n)flag=1;
				else swap(a[i],a[i+1]);
			}
		}
		if(flag)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;++i)cout<<a[i]<<" ";
			cout<<endl;
		}
	}
}