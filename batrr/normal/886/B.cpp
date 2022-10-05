#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1e6+1;
int a[maxn],n,b[maxn];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
		a[b[i]]=i+1;
	}
	int ans=a[b[0]]+1;
	for(int i=0;i<1e6;i++)
		if(a[i]!=0)
			ans=min(ans,a[i]);
	cout<<b[ans-1];
}