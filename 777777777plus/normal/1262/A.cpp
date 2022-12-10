#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,l[N],r[N];

void work(){
	int R=1,L=1e9;
	for(int i=1;i<=n;++i)R=max(R,l[i]),L=min(L,r[i]);
	cout<<max(0,R-L)<<endl;
}

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>l[i]>>r[i];
		work();
	}
}