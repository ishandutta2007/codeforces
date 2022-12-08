#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int T;
int n;
int a[N];
int f[105][20005];
bool o[20005];

int main(){
	cin>>T;
	for(int i=1;i<=20000;++i){
		for(int j=2;j*j<=i;++j)
		if(i%j==0){
			o[i]=1;
		}
	}
	while(T--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;++i)cin>>a[i],ans+=a[i];
		if(o[ans]){
			cout<<n<<endl;
			for(int i=1;i<=n;++i)cout<<i<<" ";
			cout<<endl;
			continue;
		}
		for(int i=1;i<=n;++i)
		if(a[i]&1){
			cout<<n-1<<endl;
			for(int j=1;j<=n;++j)if(j!=i)cout<<j<<" ";
			cout<<endl;
			break;
		}
	}
}