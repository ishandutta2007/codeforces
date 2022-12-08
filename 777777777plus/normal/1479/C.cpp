#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2+5;

int n;
int g[N][N];
int l,r; 
 
int main(){
	cin>>l>>r;
	if(l==1){
		--r;
		r=r-l+1;
		int tot,f;
		for(tot=2,f=1;f<=r;f=f*2+1,++tot){
			for(int j=1;j<tot;++j){
				g[tot][j]=1<<tot-2;
			}
		}
		f=(f-1)/2;
		--tot;
		while(f!=r){
			int t=0;
			while(f+(1<<t+1)<=r)++t;
			++tot;
			for(int j=1;j<=t+1;++j){
				g[tot][j]=f+1;
			}
			f+=1<<t;
		}
		vector<tuple<int,int,int>> ans;
		cout<<"YES"<<endl;
		++tot;
		for(int i=1;i<tot;++i){
			g[tot][i]=1;
		}
		for(int i=1;i<=tot;++i)
		for(int j=1;j<i;++j)
		if(g[i][j]){
			if(j==1)g[i][j]+=l-1;
			ans.push_back(make_tuple(tot-i+1,tot-j+1,g[i][j]));
		}
		cout<<tot<<" "<<ans.size()<<endl;
		for(int i=0;i<ans.size();++i){
			cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<endl;
		}
	}
	else{
		--r;--l;
		r=r-l+1;
		int tot,f;
		for(tot=2,f=1;f<=r;f=f*2+1,++tot){
			for(int j=1;j<tot;++j){
				g[tot][j]=1<<tot-2;
			}
		}
		f=(f-1)/2;
		--tot;
		while(f!=r){
			int t=0;
			while(f+(1<<t+1)<=r)++t;
			++tot;
			for(int j=1;j<=t+1;++j){
				g[tot][j]=f+1;
			}
			f+=1<<t;
		}
		vector<tuple<int,int,int>> ans;
		cout<<"YES"<<endl;
		++tot;
		for(int i=2;i<tot;++i){
			g[tot][i]=1;
		}
		for(int i=1;i<=tot;++i)
		for(int j=1;j<i;++j)
		if(g[i][j]){
			if(j==1)g[i][j]+=l-1;
			ans.push_back(make_tuple(tot-i+1,tot-j+1,g[i][j]));
		}
		cout<<tot<<" "<<ans.size()<<endl;
		for(int i=0;i<ans.size();++i){
			cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<endl;
		}
		
	}
}