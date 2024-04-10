#include<bits/stdc++.h>
using namespace std;
int T,a[100003],b[100003],c[100003],n,m,ans[100003],ANS[100003];
vector<int>v[100003];
int main(){
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)ANS[i]=-1;
		for(int i=0;i<n;i++)v[i].clear();
		for(int i=0;i<n;i++)scanf("%d",a+i),a[i]--;
		for(int i=0;i<n;i++)scanf("%d",b+i),b[i]--;
		for(int i=0;i<n;i++)
			if(b[i]==a[i])
				ANS[a[i]]=i;
		for(int i=0;i<n;i++)
			if(b[i]!=a[i])
				v[b[i]].push_back(i);
		for(int i=0;i<m;i++)scanf("%d",c+i),c[i]--;
		int lstok=-1;bool ok=1;
		for(int i=m-1;i>=0;i--){
			if(v[c[i]].size()){
				ans[i]=v[c[i]].back();
				v[c[i]].pop_back();
			}else{
				if(lstok!=-1)ans[i]=ans[lstok];
				else if(ANS[c[i]]!=-1)ans[i]=ANS[c[i]];
				else ok=0;
			}
			lstok=m-1;
		}
		for(int i=0;i<n;i++)if(v[i].size())ok=0;
		if(ok){
			cout<<"YES\n";
			for(int i=0;i<m;i++)printf("%d ",ans[i]+1);
			cout<<endl;
		}else cout<<"No\n";
	}
}