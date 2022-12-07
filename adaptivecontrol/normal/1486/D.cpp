#include<bits/stdc++.h>
using namespace std;
int k,n,a[200003],b[200003];
bool check(int x){
	for(int i=0;i<n;i++)
		if(x<=a[i])
			b[i+1]=1;
		else
			b[i+1]=-1;
	for(int i=1;i<=n;i++)
		b[i]+=b[i-1];
	int minn=19260817;
	for(int i=k;i<=n;i++){
		minn=min(minn,b[i-k]);
		if(b[i]-minn>0)return 1;
	}return 0;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	int l=1,r=n;
	while(l!=r){
		int mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
		if(check(l+1))l++;
		if(!check(r))r--;
	}cout<<l;
}