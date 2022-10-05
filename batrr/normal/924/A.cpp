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
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0);

using namespace std;                    
const ll maxn=1e6+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e17,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
int n,m;
string s[60];
bool used[60][60],usedr[60],usedc[60];
set<int>row,col;
void get(int x, int y){
	if(used[x][y])
		return;
	used[x][y]=1;
	
	row.insert(x);
	col.insert(y);

	for(int j=1;j<=m;j++)
		if(s[x][j]=='#')
			get(x,j);
	
	for(int i=1;i<=n;i++)
		if(s[i][y]=='#')
			get(i,y);
}
bool  check(){
	set<int>:: iterator i,j;
	
	for(i=row.begin();i!=row.end();i++)
	    if(usedr[*i])
			return false;
		else
			usedr[*i]=1;
	
	for(j=col.begin();j!=col.end();j++)
		if(usedc[*j])
			return false;
		else
			usedc[*j]=1;
	
	for(i=row.begin();i!=row.end();i++){
		for(j=col.begin();j!=col.end();j++){
			if( s[*i][*j]!='#')
				return false;
		}
	} 
	row.clear();
	col.clear();
	return true;
}
int main(){
	Bystro
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]='@'+s[i];
	}		
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='#'){
				get(i,j);
				if(!check()){
					cout<<"No";
					return 0;
				}
			}
		}
	}
	cout<<"Yes"<<endl;
}