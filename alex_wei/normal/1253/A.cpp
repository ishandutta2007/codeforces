#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a[100005],b[100005],c; 
int main()
{
	cin>>t;
	while(t--){
		cin>>n;
		int pd=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			cin>>b[i];
			int c=b[i]-a[i];
			if(pd!=-1){
				if(c<0)pd=-1;
				else if(c>0){
					if(pd==0)pd=c;
					else if(pd!=c)pd=-1;
				}
				else if(pd>0)pd=1e5;
			}
		}
		if(pd==-1)cout<<"NO\n";
		else cout<<"YES\n"; 
	}
    return 0;
}