#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003],b[200003];
vector<int>v;
bool check(int x){
	int cnt=0;
	for(int i=0;i<n;i++)
		if(cnt<=a[i]&&x-cnt-1<=b[i])
			cnt++;
	return cnt>=x;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d%d",a+i,b+i),swap(a[i],b[i]);
		int l=0,r=n,mid;
		while(l!=r){
			mid=(l+r+1)/2;
			if(check(mid))
				l=mid;
			else
				r=mid-1;
		}cout<<l<<endl;
	}
}