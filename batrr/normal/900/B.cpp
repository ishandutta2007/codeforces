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
const int maxn=1e6+123,infi=1e9;
const ll infl=1e18; 
int a,b,c;
int main(){              
	//                           IO
	cin>>a>>b>>c;
	int g=__gcd(a,b);
	a/=g,
	b/=g;
	for(int i=0;i<5000000;i++){
		//cout<<a/b;
		if(a/b==c && i!=0){
			cout<<i;
			return 0;
		}
		a=a%b*10;
	}
	cout<<-1;
}