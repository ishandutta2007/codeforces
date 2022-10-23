#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;   
int x[4000],y[4000],n,s;
vector<pair<int,int> > v;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
            x[i]+=2000;
            y[i]+=2000;
    }
    for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                    if((x[i]+x[j])%2==0&&(y[i]+y[j])%2==0) v.push_back(make_pair(x[i]+x[j],y[i]+y[j]));
            }
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
            pair<int,int> p=make_pair(x[i]<<1,y[i]<<1);
            s=s+upper_bound(v.begin(),v.end(),p)-lower_bound(v.begin(),v.end(),p);
    }
    cout<<s<<endl;        
	//system("pause");
	return 0;
}