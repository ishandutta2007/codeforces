#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1555;
int n,m,a[N][N],b[N][N],c[N],d[N],cc[N],e[N];
bitset<N> t[N],s;
vector<int> v; 
bool cmpa(int i,int j){
	int k;
	for(k=1;k<=m;k=k+1)
		if(a[i][k]!=a[j][k])
			return a[i][k]<a[j][k];
	return 0;
}
bool cmpb(int i,int j){
	int k;
	for(k=1;k<=m;k=k+1)
		if(b[i][k]!=b[j][k])
			return b[i][k]<b[j][k];
	return 0;
}
int main(){
	int i,j,k,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",a[i]+j);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",b[i]+j);
	for(i=1;i<=n;i++)
		c[i]=i,d[i]=i;
	stable_sort(c+1,c+n+1,cmpa);
	stable_sort(d+1,d+n+1,cmpb);
	for(i=1;i<=n;i++){
		b[d[i]][0]=c[i];
		for(j=1;j<=m;j++)
			if(a[c[i]][j]!=b[d[i]][j]){
				cout<<-1;
				return 0;
			}
	}
	for(j=0;j<=m;j++)
		for(i=1;i<n;i++)
			if(b[i][j]<=b[i+1][j])
				t[j][i]=1;
	for(i=1;i<n;i++)
		s[i]=1;
	for(i=0;i<=m;i++){
		x=0;
		for(j=0;j<=m;j++){
			if(e[j])
				continue;
			if((t[j]&s)==s){
				v.push_back(j);
				e[j]=1;
				for(k=1;k<n;k++)
					if(b[k][j]<b[k+1][j])
						s[k]=0;
				x=1;
				break;
			}
		}
		if(e[0]==1)
			break;
		if(!x){
			cout<<-1;
			return 0;
		}
	}
	cout<<v.size()-1<<endl;
	for(i=v.size()-2;i>=0;i--)
		cout<<v[i]<<' ';
	return 0;
}