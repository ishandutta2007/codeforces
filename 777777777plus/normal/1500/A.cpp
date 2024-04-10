#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 5e6+5;

int n;
int a[N],b[N];
int cnt[N];
vector<int> c,v[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=5e6;++i)
	if(cnt[i]>=2){
		c.push_back(i);
	}
	if(c.size()>=2){
		int cc;
		cc=2;
		vector<int> ans;
		for(int i=1;i<=n;++i)
		if(a[i]==c[0]){
			--cc;
			ans.push_back(i);
			if(!cc)break;
		}
		cc=2;
		for(int i=1;i<=n;++i)
		if(a[i]==c[1]){
			--cc;
			ans.push_back(i);
			if(!cc)break;
		}
		puts("YES");
		cout<<ans[0]<<" "<<ans[2]<<" "<<ans[1]<<" "<<ans[3]<<endl;
		return 0;
	}
	else if(c.size()==1){
		if(cnt[c[0]]>=4){
			int cc=4;
			puts("YES");
			for(int i=1;i<=n;++i)
			if(a[i]==c[0]){
				--cc;
				cout<<i<<" ";
				if(!cc)break;
			}
			return 0;
		}
		int cc=2;
		for(int i=1;i<=n;++i)
		if(a[i]==c[0]){
			--cc;
			v[c[0]*2].push_back(i);
			if(!cc)break;
		}
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i)if(!cnt[a[i]])b[++b[0]]=i,cnt[a[i]]=1;
	for(int i=1;i<=b[0];++i)
	for(int j=1;j<i;++j){
		int t=a[b[i]]+a[b[j]];
		if(v[t].size()){
			puts("YES");
			cout<<v[t][0]<<" "<<v[t][1]<<" "<<b[i]<<" "<<b[j]<<endl;
			return 0;
		}
		v[t].push_back(b[i]);
		v[t].push_back(b[j]);
	}
	puts("NO");
}