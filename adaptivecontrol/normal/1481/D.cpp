#include<bits/stdc++.h>
using namespace std;
int T,n,m;
string s[1003];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++)cin>>s[i];
		pair<int,int>nw=make_pair(-1,-1);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(s[i][j]==s[j][i]||m%2)
					nw=make_pair(i,j);
		if(nw.first!=-1){
			cout<<"YES\n";
			for(int i=0;i<m+1;i++)
				if(i%2)
					cout<<nw.first+1<<' ';
				else
					cout<<nw.second+1<<' ';
			cout<<endl;continue;
		}
		bool ok=0;
		deque<int>v;
		for(int i=0;i<n;i++){
			int fr=0;if(i==0)fr=1;
			for(int j=0;j<n;j++)
				if(i!=j&&i!=fr&&j!=fr)
					if(s[i][j]!=s[i][fr]){
						v.push_back(i);
						nw=make_pair(i,fr);
						for(int k=0;k<m/2;k++){
							swap(nw.first,nw.second);
							v.push_front(nw.first);
						}nw=make_pair(i,j);
						for(int k=0;k<m/2;k++){
							swap(nw.first,nw.second);
							v.push_back(nw.first);
						}
						ok=1;break;
					}
			if(ok)break;
		}
		if(ok){
			cout<<"YES\n";
			for(int i=0;i<m+1;i++)
				cout<<v[i]+1<<' ';
			cout<<endl;
		}else cout<<"NO\n";
	}
}