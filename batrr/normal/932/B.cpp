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
const ll maxn=1e6+123,inf=1e9,INF=1e18,N=1e6,mod=95542721;
using namespace std;
int cnt[maxn],pre[maxn][15];
int get(int n){
	if(n<10){
		cnt[n]=n;
		return n;
	}
	int res=1,a=n;
	while(n!=0){
		if(n%10!=0)
			res*=n%10;
		n/=10;
	}
	cnt[a]=cnt[res];
	return cnt[a];
}
int main(){                 
	for(int i=1;i<=N;i++){
		for(int j=1;j<=9;j++)
			pre[i][j]=pre[i-1][j];
		pre[i][get(i)]++;	
	}
	int q,l,r,k;
	cin>>q;
	while(q--){
		cin>>l>>r>>k;
		cout<<pre[r][k]-pre[l-1][k]<<endl;
	}
}