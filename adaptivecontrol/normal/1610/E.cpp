#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
int query(int L,int x){
	int l=L,r=n,mid;
	while(l!=r){
		mid=(l+r>>1);
		if(a[mid]>=x)
			r=mid;
		else
			l=mid+1;
	}return l;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		int ans=n-2;
		for(int i=1;i<n;i++){
			if(a[n]==a[i]){
				ans=min(ans,i-1);
				continue;
			}
			int nxt=query(1,a[i]+1);
			int mid=a[nxt],res=nxt-i+1;
			while(nxt!=n){
				int Nxt=mid*2-a[i];
				if(a[n]>=Nxt){
					res++;
					nxt=query(nxt+1,Nxt);
					mid=a[nxt];
				}else
					nxt=n;
			}
			ans=min(ans,n-res);
		}
		cout<<ans<<endl;
	}
}