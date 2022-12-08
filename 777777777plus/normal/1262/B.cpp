#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,a[N],b[N];
bool vis[N];

void work(){
	int t=1;
	for(int i=1;i<=n;++i){
		if(a[i]>a[i-1])b[i]=a[i];
		else if(a[i]==a[i-1]){
			while(t<=n&&vis[t])t++;
			if(t>a[i]){
				puts("-1");
				return;
			}
			b[i]=t;
		}
		else{
			puts("-1");
			return;
		}
		vis[b[i]]=1;
	}
	for(int i=1;i<=n;++i)cout<<b[i]<<" ";
	cout<<endl;
}

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)vis[i]=0;
		work();
	}
}