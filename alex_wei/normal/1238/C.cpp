#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q,h,n,p[200005];
int main()
{
	cin>>q;
	for(int l=0;l<q;l++){
		cin>>h>>n;
		map <int,bool> c;
		for(int i=1;i<=n;i++)
			cin>>p[i],c[p[i]]=1;
		c[0]=0;
		int pos=1,ans=0;
		while(pos<n){
			if(c[p[pos]-1]){
				if(c[p[pos]-2]||p[pos]-2==0)
					pos+=2;
				else ans++,p[++pos]--;
			}
			else p[pos]=p[pos+1]+1;
		}
		cout<<ans<<endl;
	}
    return 0;
}
/*
2
5 1
5
5 3
5 4 3
*/