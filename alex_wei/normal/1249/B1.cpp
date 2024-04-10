#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q,n,p[200005],ans[200005],pd[200005];
int main()
{
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>p[i],pd[i]=0;
		for(int i=1;i<=n;i++)
			if(!pd[i]){
				int cnt=1,pos=p[i];
				pd[i]=1;
				while(pos!=i)cnt++,pos=p[pos],pd[pos]=1;
				ans[i]=cnt;
				pos=p[i];
				while(pos!=i)ans[pos]=cnt,pos=p[pos];
			}
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
    return 0;
}