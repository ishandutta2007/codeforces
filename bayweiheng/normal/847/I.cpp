/*
 * test.cpp
 *
 *
 *      Author: Fireworks
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<bitset>
#include<set>
#include<iomanip>
#include<fstream>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<list>
#include<sstream>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,long long> il;
typedef pair<long long,long long> ll;
typedef pair<ll,int> lli;
typedef pair<long long,int> li;
typedef pair<double,double> dd;
typedef pair<ii,int> iii;
typedef pair<double,int> di;
long long mod = 1000000007LL;
long long base = 10000007;
long long large = 1000000000000000000LL;




int hor[] = {1,0,-1,0};
int ver[] = {0,1,0,-1};
int n,m,p,q;
bool in(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
bool in2(int x,int y){
	return x>=0&&x<53&&y>=0&&y<53;
}
int main(){
	cin>>n>>m>>q>>p;

	vector<vector<int> > g(n,vector<int>(m,0));
	vector<vector<int> > d(53,vector<int>(53,1000));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c;
			cin>>c;
			if(c=='.') continue;
			if(c=='*') {
				g[i][j]=-1;
				continue;
			}

			int a = (int)(c-'A')+1;
			g[i][j] = a*q;

		}
	}

	int cnt = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]==-1) continue;
			for(int a=0;a<53;a++){
				for(int b=0;b<53;b++){
					d[a][b]=1000;
				}
			}
			queue<ii> q;
			d[26][26]=0;
			q.push(ii(26,26));
			long long acc=0;
			acc+=1LL*g[i][j];
			while(!q.empty()){
				ii u = q.front();
				q.pop();
				int ux=  u.first;
				int uy = u.second;
				for(int k=0;k<4;k++){
					int vx = ux+hor[k];
					int vy = uy+ver[k];
					if(in(vx-26+i,vy-26+j)&&in2(vx,vy)&&g[vx-26+i][vy-26+j]!=-1){
						if(d[vx][vy]==1000){
							d[vx][vy] = d[ux][uy]+1;
							acc+=1LL*(g[vx-26+i][vy-26+j]>>d[vx][vy]);
							if(d[vx][vy]<26){
								q.push(ii(vx,vy));
							}
						}
					}
				}
			}
			//cout<<acc<<endl;
			if(acc>1LL*p) cnt++;

		}
	}
	cout<<cnt<<endl;






	/*long long n,k;
	cin>>n>>k;
	if(n*(n-1)/2<k){
		cout<<"Impossible"<<endl;
		return 0;
	}
	vector<long long> b;
	while(k){
		long long low = 0;
		long long high = n;
		long long mid;
		long long ans;
		while(low<=high){
			mid = (low+high)/2;
			if(mid*(mid-1)/2<=k){
				ans=mid;
				low=mid+1;
			}else{
				high=mid-1;
			}
		}
		k-=ans*(ans-1)/2;
		n-=ans;
		b.push_back(ans);
		if(n==0) break;
	}
	if(k!=0LL){
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(int i=0;i<(int)b.size();i++){
		for(long long j=0;j<b[i];j++) printf("(");
		for(long long j=0;j<b[i];j++) printf(")");

	}



	while(n){
		n--;
		printf("()");
	}*/



	/*
	int totalcase;
	int testcase=0;
	cin>>totalcase;
	ofstream out;
	out.open("result.txt");

	while(totalcase--){
		testcase++;
		out<<"Case #"<<testcase<<": ";
		cout<<testcase<<": "<<endl;

		//GOGOGO




		//END
	}
	out.close();
	*/

	return 0;
}