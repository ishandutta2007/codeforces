#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=200100;
int a[N];
ll s[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		s[i]=a[i];
		if(i>=m) s[i]+=s[i-m];
	}
	for(int i=1;i<n;i++) s[i]+=s[i-1];
	for(int i=0;i<n;i++){
		if(i) putchar(' ');
		cout<<s[i];
	}
	puts("");
	return 0;
}