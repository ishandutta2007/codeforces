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
	vector<char> a(n,'.');
	for(int i=0;i<n;i++) cin>>a[i];
	int low = 0;
	int high = 2*n+100;
	int mid;
	int ans=high;
	while(low<=high){
		mid = (low+high)/2;
		int l = 0;
		bool can = true;
		for(int i=0;i<n;i++){
			while(l<n&&a[l]!='*') l++;
			if(l>=n) break;
			if(a[i]=='P'){
				if(l<i){
					if(mid<i-l){
						can=false;
						break;
					}else{
						int d = mid-(i-l);
						l = max(i+1,max(l+d+1,i+d/2+1));
					}
				}else{
					l = max(l,i+mid+1);
				}
			}
		}

		if(can){
			if(l<n) {
				for(int i=l;i<n;i++) if(a[i]=='*') can=false;
			}
		}

		if(can){
			ans=mid;
			high=mid-1;
		}else{
			low = mid+1;
		}
	}
	cout<<ans<<endl;



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
		b.push_back(ans);
		if(n==0) break;
	}
	if(k!=0LL){
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(int i=0;i<(int)b.size();i++){
		for(long long j=0;j<b[i];j++) printf("(");
		for(long long j=0;j<b[i];j++) printf(")");

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