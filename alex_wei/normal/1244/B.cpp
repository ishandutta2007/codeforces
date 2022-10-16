#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
string s;
int main()
{
	cin>>t;
	for(int l=0;l<t;l++){
		cin>>n>>s;
		int ans=0,f=-1,ls=-1;
		for(int i=0;i<n;i++)
			if(s[i]=='1'){
				if(f==-1)f=i;
				ls=i;
			}
		if(f==-1){cout<<n<<endl;continue;}
		cout<<max(n-f,max(ls+1,max(f+1,n-ls)))*2<<endl;
	}
    return 0;
}