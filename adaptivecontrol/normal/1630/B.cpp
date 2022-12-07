#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[200003],sum[200003];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<=n;i++)sum[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			sum[a[i]]++;
		}
		for(int i=1;i<=n;i++)
			sum[i]+=sum[i-1];
		pair<int,int>ans=make_pair(1145142,-1);
		for(int x=1,y=1;x<=n;x++){
			while(y<=n&&(sum[y]-sum[x-1])<k+n-(sum[y]-sum[x-1]))y++;
			if(y>n)break;
			ans=min(ans,make_pair(y-x,x));
		}
		int x=ans.second,y=ans.second+ans.first,lst=0,cnt=0,tmes=0;
		cout<<x<<' '<<y<<endl; 
		for(int i=1;i<n;i++){
			if(a[i]>=x&&a[i]<=y)cnt++;else cnt--;
			if(cnt>0&&tmes<k-1){
				cout<<lst+1<<' '<<i<<endl;
				lst=i;
				cnt=0;
				tmes++;
			}
		}
		cout<<lst+1<<' '<<n<<endl;
	}
}