#include<bits/stdc++.h>
using namespace std;
enum{N=1000009};
char s[N];
int bg[N],len[N],id,a[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,w,p2;
	for(cin>>T;T--;cout<<'\n'){
		cin>>(s+1),n=strlen(s+1);
		id=0;
		for(i=1;i<=n;++i)if(a[i]=0,s[i]=='1'){
			if(s[i-1]=='1')++len[id];
			else bg[++id]=i,len[id]=1;
		}
		w=0;
		for(i=1;i<=id;++i)w+=len[i];
		if(w==0){
			cout<<-1<<'\n';
			continue;
		}
		if(id==1&&len[1]==5){
			a[bg[1]]=4;
			goto gg;
		}
		if(w==5){
			a[bg[1]+len[1]-1]=3;
			goto gg;
		}
		p2=1;
		while(p2<w)p2*=2;
		k=1;
		while(1){
			if(w+4>p2)break;
			if(k<id){
				if(len[k]<2){++k;continue;}
				a[bg[k]]=3,w+=4,bg[k]+=3,len[k]-=3;
			}else{
				if(len[k]<3)break;
				a[bg[k]]=3,w+=4,bg[k]+=3,len[k]-=3;
			}
		}
		k=1;
		while(1){
			if(w==p2)break;
			if(len[k]<1){++k;continue;}
			a[bg[k]]=2,++w,bg[k]+=2,len[k]-=2;
		}
		gg:;
		vector<pair<int,int>>ans;
		for(i=1;i<=n;++i)if(a[i]!=-1){if(!a[i]){
			ans.push_back({i,i});
		}else{
			ans.push_back({i,i+a[i]-1});
			for(k=1;k<a[i];++k)a[i+k]=-1;
		}}
		cout<<ans.size()<<'\n';
		for(auto o:ans)cout<<o.first<<' '<<o.second<<'\n';
	}
}