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
int x,y;
string s;
char a[9][9];
bool check(){    
	for(int i=x*3;i<x*3+3;i++){
		for(int j=y*3;j<y*3+3;j++){
			if(a[i][j]=='.'){
				return true;
			}
		}
	}                              
	return false;
}
int main(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j+=3){
			cin>>s;
			for(int q=0;q<3;q++)
				a[i][j+q]=s[q];
		}
	}
	cin>>x>>y;
	x--,y--;
	x%=3,y%=3;   
	if(check()){
		for(int i=x*3;i<x*3+3;i++){
			for(int j=y*3;j<y*3+3;j++){
				if(a[i][j]=='.'){
					a[i][j]='!';
				}
			}
		}
	}else{
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(a[i][j]=='.'){
					a[i][j]='!';
				}
			}
		}
	}                
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<a[i][j];
			if(j%3==2)
				cout<<" ";
		}
		cout<<endl;
		if(i%3==2)
				cout<<endl;;
	}

}