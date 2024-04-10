#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n,Q;
int cnt[2];
int a[N];

int main(){
	cin>>n>>Q;
	for(int i=1;i<=n;++i)cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<=Q;++i){
		int o,x;
		cin>>o>>x;
		if(o==1){
			cnt[a[x]]--;
			a[x]^=1;
			cnt[a[x]]++;
		}
		else{
			if(x<=cnt[1])cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
}