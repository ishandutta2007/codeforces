#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[100005],k;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]%2==0){cout<<a[i]/2;}
		else if(a[i]<0){
			if(k)cout<<a[i]/2,k=0;
			else cout<<a[i]/2-1,k=1;
		}
		else if(a[i]>0){
			if(k)cout<<a[i]/2+1,k=0;
			else cout<<a[i]/2,k=1;
		}
		cout<<endl;
	}
    return 0;
}