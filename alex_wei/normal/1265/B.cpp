#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,p[200005],pos[200005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>p[i],pos[p[i]]=i;
		int mi=1e9,mx=0;
		for(int i=1;i<=n;i++){
			mi=min(mi,pos[i]);
			mx=max(mx,pos[i]);
			if(mx-mi+1==i)cout<<'1';
			else cout<<'0';
		}
		puts("");
	}
    return 0;
}