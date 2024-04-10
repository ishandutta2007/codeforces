#include <bits/stdc++.h>
using namespace std;
map<int,int> m;
int n;
int a[2010],b[2010];
void pre(){
	for(int i=0;i<n;i++)
		b[i]=a[i];
	sort(b,b+n);
	int k=-1,num=0;
	for(int i=0;i<n;i++){
		if(k!=b[i]){
			k=b[i];
			num++;
			m[k]=num;
		}
	}
	for(int i=0;i<n;i++)
		a[i]=m[a[i]];
}
bool could2(int l,int r){
	for(int i=0;i<=n;i++)
		b[i]=0;
	for(int i=0;i<n;i++)
	if(i<l || i>r){
		b[a[i]]++;
		if(b[a[i]]>=2)return false;
	}
	return true;
}
bool could(int t){
	for(int l=0;l<=n-t;l++)
	if(could2(l,l+t-1))return true;
	return false;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	pre();
	int l=0,r=n;
	while(l<=r){
		int m=(l+r)/2;
		if(!could(m))
			l=m+1;
		else r=m-1;
	}
	cout<<l<<endl;
	return 0;
}