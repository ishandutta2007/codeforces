#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,k,a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		a[n+1]=0;
		for(int j=1;j<=k;++j){
			bool flag=0;
			for(int i=1;i<=n;++i)
			if(a[i]>=a[i+1]);
			else{
				flag=1;
				++a[i];
				if(j==k){
					cout<<i<<endl;
				}
				break;
			}
			if(!flag){
				cout<<-1<<endl;
				break;
			}
		}
		
	}
}