#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,s,a[100005],q[100005]; 
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		for(int i=1;i<=n;i++)cin>>a[i],q[i]=q[i-1]+a[i];
		if(q[n]<=s)puts("0");
		else{
			for(int i=1;i<=n;i++)
				if(q[i]>s){
					int pos=0;
					for(int j=1;j<=i;j++)
						if(a[j]>a[pos])pos=j;
					cout<<pos<<endl;
					break;
				}
		}
	}
    return 0;
}