#include<bits/stdc++.h>
using namespace std;
int n,lst[2],ans,a[100003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++){
		if(a[i]!=lst[0]&&a[i]!=lst[1]&&a[i]!=a[i+1]){
			if(a[i+1]==lst[0])
				lst[0]=a[i];
			else
				lst[1]=a[i];
			ans++;
			continue;
		}
		if(a[i]!=lst[0]){
			lst[0]=a[i];
			ans++;
			continue;
		}
		if(a[i]!=lst[1]){
			lst[1]=a[i];
			ans++;
			continue;
		}
		lst[0]=a[i];
	}
	cout<<ans;
}