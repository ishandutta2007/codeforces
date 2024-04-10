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
	vector<vector<int> > adj(n,vector<int>(1,0));
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		int low = 0;
		int high = n-1;
		int mid;
		int ans=n-1;
		while(low<=high){
			mid = (low+high)/2;
			if(adj[mid].back()>=x){
				low=mid+1;
			}else{
				ans=mid;
				high=mid-1;
			}
		}
		adj[ans].push_back(x);
	}

	for(int i=0;i<n;i++){
		if(adj[i].back()==0) continue;
		for(int j=1;j<(int)adj[i].size();j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}

	/*long long n,k;
	cin>>n>>k;
	if(n*(n-1)/2<k){
		cout<<"Impossible"<<endl;
		return 0;
	}
	vector<long long> b;
	while(k){
		long long low = 0;
		long long high = n;
		long long mid;
		long long ans;
		while(low<=high){
			mid = (low+high)/2;
			if(mid*(mid-1)/2<=k){
				ans=mid;
				low=mid+1;
			}else{
				high=mid-1;
			}
		}
		k-=ans*(ans-1)/2;
		n-=ans;
		for(long long j=0;j<ans;j++) printf("(");
		for(long long j=0;j<ans;j++) printf(")");
	}


	while(n){
		n--;
		printf("()");
	}*/



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