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
//:
using namespace std;
int a[200005],ans[200005],n,l[200005];
stack<int> s,k; 
int main()
{
    scanf("%d",&n);
    s.push(0);
    a[0]=a[n+1]=-1;
    for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            while(a[s.top()]>=a[i])s.pop();
            l[i]=s.top();
            s.push(i);
    }
    k.push(n+1);
    for(int i=n;i>0;i--){
            while(a[k.top()]>=a[i])k.pop();
            int t=k.top()-1-l[i];
            ans[t]=max(ans[t],a[i]);
            k.push(i);
    }
    for(int i=n;i>1;i--)ans[i-1]=max(ans[i-1],ans[i]);
    for(int i=1;i<n;i++)printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
	//system("pause");
	return 0;
}