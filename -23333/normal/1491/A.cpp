#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int n,q;
int ling,yi,c;
int a[100010];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>q;
	rep(i,1,n){cin>>a[i];if(a[i])yi++;else ling++;}
	rep(i,1,q){
		int type;
		cin>>type;
		if(type==1){
			int dot;
			cin>>dot;
			if(a[dot]){a[dot]=1-a[dot];yi--;ling++;}
			else{a[dot]=1-a[dot];yi++;ling--;}
		}else{
			int dot;
			cin>>dot;
			if(dot<=yi)cout<<1<<endl;else cout<<0<<endl;
			
		}
	}
	
	return 0;
}