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

using namespace std;

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
	vector<int> l(n,-1),r(n,-1);
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		l[i]=x;
		r[i]=y;
	}
	vector<bool> vis(n,false);
	int pre = -1;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=true;
			int p = i;
			while(l[p]!=-1) {
				p = l[p];
				vis[p]=true;
			}
			if(pre!=-1){
				r[pre] = p;
				l[p] = pre;
			}
			p = i;
			while(r[p]!=-1){
				p = r[p];
				vis[p]=true;
			}

			pre = p;

		}
	}

	for(int i=0;i<n;i++) cout<<l[i]+1<<" "<<r[i]+1<<endl;




	/*
	int totalcase;
	int testcase=0;
	cin>>totalcase;
	ofstream out;
	out.open("result.txt");

	while(totalcase--){
		testcase++;
		out<<"Case #"<<testcase<<": ";
		cout<<testcase<<": "<<endl;

		//GOGOGO




		//END
	}
	out.close();
	*/

	return 0;
}