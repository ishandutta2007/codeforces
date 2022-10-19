/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int N=100;
int q,f[110][10100];//if it's valid,f shall equals to the number of nodes the root shall have.
vector<int>construct(int i,int j,bool sd){//false:cis order; true: rev order.
	// printf("cons:%d,%d|%d\n",i,j,sd);
	if(f[i][j]==-1)return vector<int>{1};
	if(f[i][j]==i&&j==(i*(i+1)>>1)){
		vector<int>v;
		for(int _=1;_<=i;_++)v.push_back(_);
		if(sd)reverse(v.begin(),v.end());
		return v;
	}
	int k=f[i][j];
	if(k>=4&&f[i-k+1][j-k]){
		// puts("A");
		vector<int>v=construct(i-k+1,j-k,false);
		v.resize(i);
		int bon=0;
		for(int _=i-k+1;_<i;_+=2)v[_]=++bon;
		// printf("<QWQ>%d\n",bon);
		for(int _=0;_<i-k+1;_++)v[_]+=bon;
		bon+=i-k+1;
		for(int _=i-k+2;_<i;_+=2)v[_]=++bon;
		if(k&1)swap(*v.rbegin(),*(v.rbegin()+2));
		return v;
	}else{
		// puts("B");
		vector<int>v=construct(i-k+1,j-(k*(k-1)>>1)-(k-1),sd^1);
		if(sd){
			v.insert(v.begin(),k-1,sd^1);
			for(int _=0;_<k-1;_++)v[_]=i-_;
		}else{
			for(int _=0;_<k-1;_++)v.push_back(v.size()+1);
		}
		return v;
	}
}
int main(){
	f[1][1]=-1;
	for(int i=1;i<=N;i++)for(int j=1;j<=(i*(i+1)>>1);j++)if(f[i][j]){
		for(int k=2;i+k-1<=N;k++)
			if(!f[i+k-1][j+(k*(k-1)>>1)+(k-1)])
				f[i+k-1][j+(k*(k-1)>>1)+(k-1)]=k;
		for(int k=4;i+k-1<=N;k++)
			if(!f[i+k-1][j+k])f[i+k-1][j+k]=k;
	}
	scanf("%d",&q);
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(!f[x][y])puts("NO");
		else{puts("YES");for(auto _:construct(x,y,false))printf("%d ",_);puts("");}
	}
	return 0;
}