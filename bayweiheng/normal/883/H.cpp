/*
 * test.cpp
 *
 *
 *      Author: Fireworks
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<bitset>
#include<set>
#include<iomanip>
#include<fstream>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<list>
#include<sstream>
#include<cassert>   // assert

using namespace std;

//#define double long double

typedef pair<int,int> ii;
typedef pair<int,long long> il;
typedef pair<long long,long long> ll;
typedef pair<ll,int> lli;
typedef pair<long long,int> li;
typedef pair<double,double> dd;
typedef pair<ii,int> iii;
typedef pair<double,int> di;
long long mod = 1000000007LL;
long long base = 10000007;
long long large = 1000000000000000000LL;




int main(){


	map<char,int> comp;
	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++) comp[s[i]]++;
	int cnt = 0;
	for(map<char,int>::iterator it = comp.begin();it!=comp.end();it++){
		if((it->second)%2) cnt++;
	}
	if(cnt==0){
		cout<<1<<endl;
		string t="";
		for(map<char,int>::iterator it = comp.begin();it!=comp.end();it++){
			int x = it->second;
			while(x){
				x-=2;
				t.push_back(it->first);
			}
		}
		cout<<t;
		reverse(t.begin(),t.end());
		cout<<t<<endl;
		return 0;
	}

	vector<char> e;
	int tot = 0;
	for(map<char,int>::iterator it = comp.begin();it!=comp.end();it++){
		if((it->second)%2){
			it->second--;
			e.push_back(it->first);
		}
		tot+=it->second/2;

	}
	int p = 0;
	for(;p<=tot;p++){
		if((tot-p)%(cnt+2*p)==0) break;
	}
	int sz = (tot-p)/(cnt+2*p);
	cout<<cnt+2*p<<endl;
	for(map<char,int>::iterator it = comp.begin();it!=comp.end();it++){
		while(it->second>0&&p>0){
			it->second-=2;
			e.push_back(it->first);
			e.push_back(it->first);
			p--;
		}
		if(p==0) break;
	}
	vector<char> a;
	for(map<char,int>::iterator it = comp.begin();it!=comp.end();it++){
		while(it->second>0){
			it->second-=2;
			a.push_back(it->first);
		}
	}
	for(int i=0;i<(int)e.size();i++){
		string temp = "";
		for(int j = i*sz;j<(i+1)*sz;j++){
			temp.push_back(a[j]);
		}
		cout<<temp<<e[i];
		reverse(temp.begin(),temp.end());
		cout<<temp<<" ";
	}






	return 0;

}