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
#define op cout<<"BUG"<<endl; 
#define in insert
#define er erase
using namespace std;
const int maxn=1e5+123,inf=1e9;
int n,m,ans;
string s[101],t;
pair<int,int> vp[4];
bool used[maxn];
int si,sj,ei,ej;
void rec(int r){
	if(r>=4){
		int i=si,j=sj;
		int tt=0;
		for(int tt=0;tt<t.size();tt++){
			int g=t[tt]-48;
			i+=vp[g].f;
			j+=vp[g].s;
			if(min(i,j)<0 || i>=n || j>=m || s[i][j]=='#')
				return;	
			if(i==ei && j==ej){
				ans++;
				return; 
			}
		}                              
	}else{
		for(int i=0;i<4;i++){
			if(!used[i]){
				used[i]=1;        
				if(r==0)
					vp[i]=mp(1,0);
				if(r==1)
					vp[i]=mp(-1,0);
				if(r==2)
					vp[i]=mp(0,1);
				if(r==3)
					vp[i]=mp(0,-1);
				rec(r+1);
				used[i]=0;
			}
		}
	}
}
int main(){                                     
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];        
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='S')
				si=i,sj=j;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='E')
				ei=i,ej=j;
	cin>>t;
	rec(0);
	cout<<ans;
}