#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n;
int a[N],b[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)cin>>b[i];
		bool flag=1;
		int cnt[3]={0,0,0};
		for(int i=1;i<=n;++i)cnt[a[i]+1]++;
		for(int i=n;i>=1;--i){
			cnt[a[i]+1]--;
			if(a[i]!=b[i]){
				if(b[i]>a[i]){
					if(!cnt[2])flag=0;
				}
				else{
					if(!cnt[0])flag=0;
				}
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
}