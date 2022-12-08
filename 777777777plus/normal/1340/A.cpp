#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,a[N],p[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			p[a[i]]=i;
		}
		bool flag=1;
		int r=n;
		for(int i=1;i<n;++i){
			if(p[i+1]!=p[i]+1){
				if(p[i]!=r){
					flag=0;
				}
				else{
					r=n-i;
				}
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
}