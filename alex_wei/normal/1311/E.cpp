#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,d,p[5005],f[5005];
vector <int> dep[5005];
int main(){
	cin>>t;
//	freopen("testdata.in","w",stdout);
	while(t--){
		memset(p,0,sizeof(p));
		memset(f,0,sizeof(f));
		cin>>n>>d;
		int sum=0,bs=0;
		for(int i=1;i<=n;){
			int rem=min(n-i+1,1<<bs);
			p[bs]=rem,sum+=rem*bs;
			i+=rem,bs++;
		}
		if(sum>d){
			puts("NO");
			continue;
		}
		int pos=bs;
		while(sum<d){
			int k=0;
			for(int i=1;i<=n;i++)if((p[i]-1)*2>=p[i+1]+1){
				k=i;
				break;
			}
			if(!k)break;
			sum++,p[k]--,p[k+1]++;
//			for(int i=1;i<=n;i++)cout<<p[i]<<" ";
//			puts("");
		}
		if(sum<d){
			puts("NO");
			continue;
		}
		puts("YES");
		int cnt=1;
		for(int i=0;i<=n;i++)dep[i].clear();
		dep[0].push_back(1),dep[0].push_back(1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=p[i];j++){
				f[++cnt]=dep[i-1].back();
				dep[i].push_back(cnt);
				dep[i].push_back(cnt);
				dep[i-1].pop_back();
			}
		}
		for(int i=2;i<=n;i++)cout<<f[i]<<" ";
		puts("");
	}
	return 0;
}