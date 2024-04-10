#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
 
#include <cstring>
#include <string>
#include <cmath>    
#include <algorithm>
 
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>                                                      
#include <stack>
#include <list>
#include <deque>
 
#include <ctime>
#include <cassert> 
 
#define nm "C" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ld long double 
#define ll long long 
#define ull unsigned long long 
#define f first 
#define s second 
#define pb push_back               
#define p push 
#define mp make_pair 
#define o cout<<"BUG"<<endl; 
using namespace std;                    
const ll maxn=1e6+12,inf=2e9,mod=1e9+7; 
int n,a[501][501],b[501][501],x[501];
ll ans[501];
bool used[501];
int main(){ 
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int xi=n;xi>=0;xi--){
		int k=x[xi];
		used[k]=1;
		for(int i=1;i<=n;i++)
			if(used[i])
				b[i][k]=a[i][k],b[k][i]=a[k][i];                 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(used[i] && used[j])
					b[i][k]=min(b[i][k],b[i][j]+b[j][k]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(used[i] && used[j])
					b[k][i]=min(b[k][i],b[k][j]+b[j][i]);		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(used[i] && used[j])
					b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(used[i] && used[j])
					ans[xi]+=b[i][j];	
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<< " ";
}