#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
 
int T;
int n,m,a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=2;i<=n;++i)a[1]+=a[i];
		cout<<min(m,a[1])<<endl;
	}
}