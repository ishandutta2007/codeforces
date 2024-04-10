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
int n;
int main(){
	string s;
	cin>>s;
	int ans=0;
	//a, e, i, o  u
	for(int i=0;i<s.size();i++)
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
			ans++;
		else if(s[i]>='0' && s[i]<='9' && (s[i]-48)%2==1)
			ans++;
	cout<<ans;
}