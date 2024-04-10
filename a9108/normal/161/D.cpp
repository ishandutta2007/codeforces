#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define eps 1e-8
#define PB push_back
#define MP make_pair
using namespace std;
double pi=asin(1.0)*2;

vector<int> g[60000];
int num[50001][501];
int fa[60000];
int n,k;
vector<int> o;

void makeup(int i){
	num[i][0]++;
	for (int z=0;z<g[i].size();z++)
	if (g[i][z]!=fa[i]){
		for (int j=0;j<k;j++) num[i][j+1]+=num[g[i][z]][j];
	}
}

void makedown(int i){
	if (fa[i]>=0){
		for (int j=k-1;j>0;j--) num[i][j+1]+=num[fa[i]][j]-num[i][j-1];
		num[i][1]++;
	}
}
bool vi[60000];
void makeo(){
	queue<int> Q;
	for (;Q.size();Q.pop());
	o.PB(0);
	Q.push(0);
	memset(fa,-1,sizeof(fa));
	fa[0]=-2;
	for (;Q.size();Q.pop()){
		int i=Q.front();
		for (int z=0;z<g[i].size();z++){
			int j=g[i][z];
			if (fa[j]!=-1) continue;
			fa[j]=i;
			o.PB(j);
			Q.push(j);
		}
	}
}

int main(){
	scanf("%d%d",&n,&k);
	memset(num,0,sizeof(num));
	for (int i=0;i<n;i++) g[i].clear();
	for (int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		g[a].PB(b);
		g[b].PB(a);
	}
	makeo();
	for (int i=0;i<n;i++) makeup(o[n-1-i]);
	for (int i=0;i<n;i++) makedown(o[i]);
	long long ans=0;
	for (int i=0;i<n;i++) ans+=num[i][k];
	cout<<ans/2<<endl;
	return 0;
}