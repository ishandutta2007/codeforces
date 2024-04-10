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

#define nm "word" 
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
const int maxn=1e5+123,infi=1e9;
const ll infl=1e18; 
int n,a[maxn],cnt[maxn];
bool used[maxn];
//vector <pait<int,int> > ans;
int main(){              
	//                           IO
	cin>>n;
	int q=0,w=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>q && a[i]<w){
//	   		ans.pb(w,a[i]);
	   		cnt[w]++;
	   	}
	   	if(a[i]>q && a[i]>w)
	   		used[a[i]]=true;
		if(a[i]>w){
			q=w;
			w=a[i];
		}else if(a[i]>q)
			q=a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(cnt[ans]-used[ans]<cnt[i]-used[i])
			ans=i;
	}
	cout<<ans;
}