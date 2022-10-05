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
const int maxn=1e6;
int n,m;
vector<string>t[30];
string s[30];  
set<string>names;
int main(){        
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i]>>m;
		for(int j=0;j<m;j++){
			string g;
			cin>>g;
			for(int q=0;q<g.size()/2;q++)
				swap(g[q],g[g.size()-q-1]);
			t[i].pb(g);
		}
		names.insert(s[i]);
	}
	cout<<names.size()<<endl;
	for(set<string>:: iterator it=names.begin();it!=names.end();it++){
		cout<<*it<<" ";
		vector<string>nums;
		for(int i=0;i<n;i++){
			if(s[i]==*it){
				for(int j=0;j<t[i].size();j++)
					nums.pb(t[i][j]);
			}
		}
		sort(nums.begin(),nums.end());
		vector<string>ans;
		for(int j=0;j<nums.size();j++){
			if(j+1!=nums.size() && nums[j].size()>nums[j+1].size()){
				ans.pb(nums[j]);
				continue;
			}
			for(int q=0;q<nums[j].size();q++){
				if(j+1==nums.size() || nums[j][q]!=nums[j+1][q]){
					ans.pb(nums[j]);
					break;
				}
			}
		}
		cout<<ans.size()<<" ";
		for(int j=0;j<ans.size();j++){
			for(int q=ans[j].size()-1;q>=0;q--)
				cout<<ans[j][q];
			cout<<" ";
		}
		cout<<endl;

	}
}