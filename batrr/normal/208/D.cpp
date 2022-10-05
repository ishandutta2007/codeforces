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
#define o cout<<"BUG"<<endl; 
using namespace std;                    
const int maxn=1e5+123,inf=2e9,mod=1e9+7;  
ll n,cnt[5],cur,a[100],b[5];
int main(){
	cin>>n;  
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<5;i++)
		cin>>b[i];
	for(int i=0;i<n;i++){
		cur+=a[i];
		for(int j=4;j>=0;j--)
			cnt[j]+=cur/b[j],cur%=b[j];
	}
	for(int j=0;j<5;j++)
		cout<<cnt[j]<<" ";
	cout<<endl<<cur;
}