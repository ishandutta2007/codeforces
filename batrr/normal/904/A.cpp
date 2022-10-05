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
int n,q,w,e,a,b,c,ans;
int main(){   
	cin>>c>>b>>a>>n;
	for(int i=1;i<=200;i++){
		for(int j=1;j<=200;j++){
			for(int q=1;q<=200;q++){
				if(a<=i && a*2>=i && 
					b<=j && b*2>=j &&
					c<=q && c*2>=q &&
					n<=min(i,min(j,q)) && 2*n>=i && 2*n<j && 2*n<q &&
					i<j && j<q
				){
					cout<<q<<endl<<j<<endl<<i;
					return 0;
				}
			}
		}
	}
	cout<<-1;
}