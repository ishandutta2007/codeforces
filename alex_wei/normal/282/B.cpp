#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int n,a[N],g[N],s,pos;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&g[i]),s+=a[i];
	for(int i=1;i<=n;i++)
		if(s>500)s-=1000,cout<<'G';
		else cout<<'A';
    return 0;
}