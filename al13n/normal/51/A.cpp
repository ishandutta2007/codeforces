#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <string.h>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <limits>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define forv(i,v) forn(i,(int)v.size())
#define time asdtime
#define pb push_back
#define lng long long
#define mp make_pair
#define iinf 1000000000
#define prev asdprev
#define next asdnext



int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	set<string> st;
	forn(i,n){
		string s,t;
		if(i)
			cin>>t;
		cin>>s;
		cin>>t;
		s+=t[1];
		s+=t[0];
		t=s;
		for(int i=1;i<4;++i){
			string p=s.substr(i)+s.substr(0,i);
			if(p<t)
				t=p;
		}
		st.insert(t);
	}
	cout<<st.size();

	return 0;
}