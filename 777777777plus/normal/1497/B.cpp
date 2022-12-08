#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,m;
int a[N],cnt[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		cnt[m]=0;
		for(int i=0;i<m;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),cnt[a[i]%m]++;
		int ans=0;
		for(int i=0;2*i<=m;++i){
			if(!cnt[i]&&!cnt[m-i])continue;
			if(i==m-i||i==0){
				++ans;
			}
			else if(cnt[i]==cnt[m-i]){
				++ans;
			}
			else{
				int x=cnt[i],y=cnt[m-i];
				if(x>y)swap(x,y);
				y-=x+1;
				++ans;
				ans+=y;
			}
		}
		cout<<ans<<endl;
	}
}