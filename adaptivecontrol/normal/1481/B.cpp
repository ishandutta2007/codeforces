#include<bits/stdc++.h>
using namespace std;
int T,n,k,h[103];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n;i++)
			scanf("%d",h+i);
		bool ok=1,flag;
		for(int i=0;i<k;i++){
			flag=0;int ans=-1;
			for(int j=1;j<n;j++)
				if(h[j]>h[j-1]){
					flag=1;
					h[j-1]++;
					ans=j;break;
				}
			if(!flag){ok=0;break;}
			if(i==k-1)cout<<ans<<endl;
		}if(!ok)cout<<-1<<endl;
	}
}