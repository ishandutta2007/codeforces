#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,x[N],pre[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i],pre[x[i]]++;
	for(int i=1;i<=1e5;i++)pre[i]+=pre[i-1];
	cin>>q;
	for(int i=1;i<=q;i++){
		int v;
		cin>>v;
		cout<<pre[min(100000,v)]<<endl;
	}
	return 0;
}