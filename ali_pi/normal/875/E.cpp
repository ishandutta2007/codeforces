#include<bits/stdc++.h>

using namespace std;

int s1,s2,n;
int a[100010];

bool check(int d){
	int l,r;
	l=a[n]-d,r=a[n]+d;
	for(int i=n-1;i>0;i--){
		if(l<=a[i]&&a[i]<=r)l=a[i]-d,r=a[i]+d;
		else l=max(l,a[i]-d),r=min(r,a[i]+d);
	}
	return (s1>=l&&s1<=r)||(s2>=l&&s2<=r);
} 
int main(){
	cin>>n>>s1>>s2;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=abs(s1-s2),r=1000000000;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l;
}