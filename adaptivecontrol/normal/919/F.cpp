#include<bits/stdc++.h>
using namespace std;
int win[503][503],cntt[503][503],cnt;
bool vis[503][503];
map<vector<int>,int>mp;
vector<int>v[503],nwx,nwy;
vector<pair<int,int> >g[503][503];
int main(){
	for(int i=8;i>=0;i--)
		for(int j=0;j+i<=8;j++)
			for(int k=0;k+j+i<=8;k++)
				for(int l=0;l+k+j+i<=8;l++){
					v[cnt].push_back(i);
					v[cnt].push_back(j);
					v[cnt].push_back(k);
					v[cnt].push_back(l);
					v[cnt].push_back(8-i-j-k-l);
					mp[v[cnt]]=cnt;
					cnt++;
				}
	vector<int>tmp;
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++)
			for(int k=1;k<5;k++)
				for(int l=1;l<5;l++)
					if(v[i][k]&&v[j][l]){
						tmp=v[i];
						tmp[k]--;
						tmp[(k+l)%5]++;
						g[j][mp[tmp]].push_back(make_pair(i,j));
						cntt[i][j]++;
					}
	}
	queue<pair<pair<int,int>,bool> >q;
	for(int i=0;i<cnt;i++)
		for(int j=0;j<cnt;j++)
			win[i][j]=2;
	for(int i=1;i<cnt;i++){
		win[0][i]=0;
		win[i][0]=1;
		q.push(make_pair(make_pair(0,i),0));
		q.push(make_pair(make_pair(i,0),1));
	}
	while(q.size()){
		int nwx=q.front().first.first,nwy=q.front().first.second,nwres=q.front().second;q.pop();
		for(int i=0;i<g[nwx][nwy].size();i++){
			int newx=g[nwx][nwy][i].first,newy=g[nwx][nwy][i].second;
			cntt[newx][newy]--;
			if(win[newx][newy]!=0&&nwres){
				win[newx][newy]=0;
				q.push(make_pair(make_pair(newx,newy),0));
			}
			if(win[newx][newy]!=0&&!cntt[newx][newy]){
				win[newx][newy]=1;
				q.push(make_pair(make_pair(newx,newy),1));
			}
		}
	}
	int T,f,x;
	vector<int>A(5),B(5);
	cin>>T;
	while(T--){
		cin>>f;
		for(int i=0;i<5;i++){A[i]=0;B[i]=0;}
		for(int i=0;i<8;i++){
			scanf("%d",&x);
			A[x]++;
		}
		for(int i=0;i<8;i++){
			scanf("%d",&x);
			B[x]++;
		}
		if(f==0){
			if(win[mp[A]][mp[B]]==2)
				cout<<"Deal\n";
			else if(win[mp[A]][mp[B]]==0)
				cout<<"Alice\n";
			else
				cout<<"Bob\n";
		}
		else{
			if(win[mp[B]][mp[A]]==2)
				cout<<"Deal\n";
			else if(win[mp[B]][mp[A]]==0)
				cout<<"Bob\n";
			else
				cout<<"Alice\n";
		}
	}
}