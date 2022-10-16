#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],l1[N],r1[N],l2[N],r2[N];
int main()
{
	cin>>n;
	if(n<3)cout<<"0",exit(0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	l1[1]=l2[1]=1,r1[n]=r2[n]=n;
	for(int i=2;i<=n;i++){
		l1[i]=a[i]<a[l1[i-1]]?i:l1[i-1];
		l2[i]=a[i]>a[l2[i-1]]?i:l2[i-1];
	}
	for(int i=n-1;i>0;i--){
		r1[i]=a[i]<a[r1[i+1]]?i:r1[i+1];
		r2[i]=a[i]>a[r2[i+1]]?i:r2[i+1];
	}
	for(int i=2;i<n;i++){
		if(a[l1[i-1]]<a[i]&&a[i]>a[r1[i+1]])
			cout<<"3\n"<<l1[i-1]<<" "<<i<<" "<<r1[i+1],exit(0);
		if(a[l2[i-1]]>a[i]&&a[i]<a[r2[i+1]])
			cout<<"3\n"<<l2[i-1]<<" "<<i<<" "<<r2[i+1],exit(0);
	}
	puts("0");
	return 0;
}