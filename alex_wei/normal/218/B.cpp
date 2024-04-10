#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,a[N],b[N],s1,s2;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i],b[i]=a[i];
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int i=1;i<=m;i++){
			if(!a[i])continue;
			if(a[i]>a[pos])pos=i;
		}
		s1+=a[pos]--;
	}
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int i=1;i<=m;i++){
			if(!b[i])continue;
			if(!pos||b[i]<b[pos])pos=i;
		}
		s2+=b[pos]--;
	}
	cout<<s1<<" "<<s2<<endl;
	return 0;
}