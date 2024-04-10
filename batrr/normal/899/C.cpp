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
int n;

		int sum1=0,sum2=0;
int main(){  
    cin>>n;    
	if(n%2==0){
		int a=0,b=0;
		vector<int>ans;
		for(int i=1,j=0;i<=n;i+=2,j++){
			if(j%2==0){
				sum1+=i;
				sum2+=i+1;
				ans.pb(i); 
			}else{
				sum1+=i+1;
				sum2+=i; 
				ans.pb(i+1);
			}
		}
		cout<<abs(sum1-sum2)<<endl<<ans.size()<<" ";
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
	}else{                
		vector<int>ans;
		for(int i=2,j=0;i<=n;i+=2,j++){
			if(j%2==0){
				sum1+=i;
				sum2+=i+1;
				ans.pb(i); 
			}else{
				sum1+=i+1;
				sum2+=i; 
				ans.pb(i+1);
			}
		}     
		if(sum1>sum2)
			sum2++;
		else{
			sum1++       ;
			ans.pb(1);
		}
		cout<<abs(sum1-sum2)<<endl<<ans.size()<<" ";
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
	}
}