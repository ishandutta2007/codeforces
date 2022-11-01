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
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<char,bool> called;
	for(int i=0;i<26;i++) called[(char)('a'+i)]=false;
	for(int i=0;i<n;i++){
		if(s[i]!='*') called[s[i]]=true;
	}
	vector<string> w;
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		string t;
		cin>>t;
		bool flag = true;
		for(int i=0;i<n;i++){
			if(s[i]=='*'){
				if(called[t[i]]){
					flag = false;
				}
			}else{
				if(s[i]!=t[i]){
					flag = false;
				}
			}
		}
		if(flag){
			w.push_back(t);
		}
	}
	m = (int)w.size();
	int cnt = 0;
	for(int i=0;i<26;i++){
		char c = (char)('a'+i);
		if(!called[c]){
			bool can = true;
			for(int j=0;j<m;j++){
				bool have = false;
				for(int k=0;k<n;k++){
					if(w[j][k]==c) have = true;
				}
				if(!have){
					can = false;
				}
			}
			if(can) cnt++;
		}
	}
	cout<<cnt<<endl;


	return 0;

}