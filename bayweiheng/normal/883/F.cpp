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
	set<string> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		reverse(t.begin(),t.end());
		string temp = "";
		for(int i=0;i<(int)t.length();i++){
			if(temp.length()>0&&temp[temp.length()-1]=='h'){
				if(t[i]=='k') continue;
			}
			temp.push_back(t[i]);
		}
		t = temp;
		reverse(t.begin(),t.end());
		temp = "";
		int l = (int)t.length();
		for(int i=0;i<l;i++){
			if(t[i]=='u'){
				temp = temp+"oo";
				continue;
			}
			temp.push_back(t[i]);
		}
		t = temp;
		s.insert(t);
	}
	cout<<(int)s.size()<<endl;




	return 0;

}