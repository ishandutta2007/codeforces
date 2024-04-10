#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
int t,n;
const int N=1e5+444;
int cnt,a[N],b[N],c[N];
long long miner;
int main(){
//	freopen("p.in","r",stdin);
//	freopen("p.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;x++){
		cin>>n;
		
		miner=10000000000000;
		for(int i=1;i<=n;i++)
			{cin>>a[i];
			if(a[i]<miner)miner=a[i];
			}
		//cout<<miner<<endl;
		cnt=0;
		for(int i=1;i<=n;i++)if(a[i]%miner==0){
			cnt++;
			b[cnt]=i;c[cnt]=a[i];
		}
		
		sort(c+1,c+1+cnt);
		for(int i=1;i<=cnt;i++)a[b[i]]=c[i];
		
		//for(int i=1;i<=n;i++)cout<<a[i]<<endl;

		bool flag=0;
		for(int i=1;i<n;i++)if(a[i]>a[i+1])flag=1;
		if(flag)cout<<"NO";else cout<<"YES";
		cout<<endl;
	}
	return 0;
}