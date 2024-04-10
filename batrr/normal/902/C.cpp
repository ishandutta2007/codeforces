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
  
#define nm "i" 
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
const int maxn=1e6;
vector<int>g[maxn];
ll n,cnt[maxn],p[maxn],a[maxn];
int main(){
	cin>>n; 
	for(int i=0;i<=n;i++)
		cin>>cnt[i];
	vector<int>ans;
	for(int i=1;i<=n;i++){
		if(cnt[i]>=2 && cnt[i-1]>=2){
			cout<<"ambiguous"<<endl;
			int q=0,e=0;
			for(int j=0;j<=n;j++){
				for(int w=0;w<cnt[j];w++)
					cout<<q<<" ";
				q+=cnt[j];	
			}
			cout<<endl;
			q=0;
			for(int j=0;j<=n;j++){
				for(int w=0;w<cnt[j];w++){
					if(j==i){
						cout<<q-1<<" ";
						i=-10;
					}else
						cout<<q<<" ";
				}
				q+=cnt[j];
			}
			return 0;
		}
	}
	cout<<"perfect";
}