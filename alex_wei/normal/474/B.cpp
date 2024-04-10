#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int n,m,a[N],buc[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
		for(int j=a[i-1]+1;j<=a[i];j++)buc[j]=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int q;
		cin>>q;
		printf("%d\n",buc[q]);
	}
    return 0;
}