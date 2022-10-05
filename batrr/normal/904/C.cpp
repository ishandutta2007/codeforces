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
const int maxn=1e6+123,mod=1e9+7;     
int n,ans,cnt;                     
bool a[50];
string s;
char d; 
bool k;
int main(){                                                          
	cin>>n;
	for(int i=0;i<26;i++)
		a[i]=true;
	cnt=26;
	for(int y=0;y<n-1;y++){
		cin>>d;
		if(d=='!'){
			if(k==true)
				ans++;
			cin>>s;
			set<char> c;
			for(int i=0;i<s.size();i++)
				c.in(s[i]-'a');
			for(int i=0;i<26;i++){
				if(a[i]==true && c.find(i)==c.end()){
					a[i]=false;
					cnt--;
				}
			}
		}
		if(d=='.'){
			cin>>s;
			set<char> c;
			for(int i=0;i<s.size();i++)
				c.in(s[i]-'a');
			for(int i=0;i<26;i++){
				if(a[i]==true && c.find(i)!=c.end()){
					a[i]=false;
					cnt--;
				}
			}
		}
		if(d=='?'){  
			if(k==true)
				ans++;
			cin>>s;
			if(a[s[0]-'a']==true){
				a[s[0]-'a']=false;
				cnt--;
			}
		}
		if(cnt==1){
			k=true;
		//	cout<<n;
		}
		
	}
	cout<<ans;
}