#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N];
bool b[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		int c=0;
		for(i=1;i<=n;++i){
			cin>>a[i];b[i]=0;
			if(a[i])++c;
		}
		if(c&1){
			cout<<"-1\n";
			continue;
		}
		int las=0,f=0,cnt=n;
		for(i=1;i<=n;++i){
			if(a[i]){
				if(f){
					if(a[i]==las)b[i]=1,--cnt;
					f=0;
				}else las=a[i],f=1;
			}
		}
		cout<<cnt<<'\n';
		for(i=1;i<=n;){
			if(i==n||!b[i+1]){
				cout<<i<<' '<<i<<'\n';
				++i;
			}else{
				cout<<i<<' '<<i+1<<'\n';
				i+=2;
			}
		}
	}
}