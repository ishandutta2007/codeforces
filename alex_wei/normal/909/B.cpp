#include<bits/stdc++.h>
using namespace std;
int n,k,t[102][102],cnt;
int main()
{
	cin>>n;
	while(cnt<n*(n+1)/2){
		k++;
		int l=0;
		while(l<n){
			int pd=0;
			for(int i=l+1;i<=n;i++)
				if(!t[l][i]){t[l][i]=pd=1,l=i;break;}
			if(!pd)l++;
			else cnt++;
		}
	}
	cout<<k;
	return 0;
}