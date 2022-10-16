#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[2005],l,r,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=n;i++){
		map <int,int> d;
		int cnt=0;
		for(int j=1;j<=i;j++){
			if(d[a[j]])break;
			d[a[j]]=1;
			cnt++;
		}
		for(int j=n;j>i;j--){
			if(d[a[j]])break;
			d[a[j]]=1;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<n-ans<<endl;
    return 0;
}