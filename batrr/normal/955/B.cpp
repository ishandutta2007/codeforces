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
const ll maxn=11e5+123,g=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
string s;
int cnt[500];
vector<int>v;
int main(){                                                                                   
	cin>>s;
	for(int i=0;i<s.size();i++)
		cnt[s[i]-'a']++;
	int c1=0,c2=0;
	for(int i=0;i<500;i++)
		if(cnt[i]==1)
			c1++;
		else
		if(cnt[i]>1)
			c2++;
	
	if(c2+c1>4)
		cout<<"NO"; 
	if(c1+c2==4)
		cout<<"YES";
	if(c1+c2==3){
		if(c1==3)
			cout<<"NO";
		else
			cout<<"YES";
	}
	if(c1+c2==2){
		if(c2==2)
			cout<<"YES";
		else
			cout<<"NO";
	}
    if(c1+c2==1)
    	cout<<"NO";	
}