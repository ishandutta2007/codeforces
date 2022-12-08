#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,q[N];
bool vis[N];

int main(){
	cin>>T;
	for(int i=2;i<N;++i){
		if(!vis[i])q[++q[0]]=i;
		for(int j=2;j*i<N;++j){
			vis[i*j]=1;
		}
	}
	while(T--){
		cin>>n;
		for(int i=1;i<=q[0];++i)
		if(q[i]-1>=n){
			for(int j=i+1;j<=q[0];++j)
			if(q[j]-q[i]>=n){
				cout<<1ll*q[i]*q[j]<<endl;
				break;
			}
			break;
		}
	}
}