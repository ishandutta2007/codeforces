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
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define X    first
#define Y    second
//:
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
//
int n,k,f[300005],ans;
pair<pair<int,int>,int> p[300005];
set<pair<int,int> > s;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i].X.X,&p[i].X.Y),p[i].Y=i;
    sort(p+1,p+n+1);
    for(int i=1;i<k;i++)s.insert(mp(p[i].X.Y,i));
    for(int i=k;i<=n;i++){
            s.insert(mp(p[i].X.Y,i));
            f[i]=max(0,(s.begin()->X)-p[i].X.X+1);
            s.erase(s.begin());
    }
    s.clear();
    for(int i=k;i<=n;i++)if(f[i]>f[ans])ans=i;
    if(!f[ans]){
                printf("0\n");
                for(int i=1;i<k;i++) printf("%d ",i);
                printf("%d\n",k);
                return 0;
    }
    for(int i=1;i<k;i++)s.insert(mp(p[i].X.Y,i));
    for(int i=k;i<=n;i++){
            s.insert(mp(p[i].X.Y,i));
            if(i==ans) break;
            s.erase(s.begin());
    }
    printf("%d\n",f[ans]);
    int o=0;
    for(int i=1;i<=n;i++){
            if(!s.count(mp(p[i].X.Y,i))) continue;
            o++;
            if(o==k)printf("%d\n",p[i].Y);
            else printf("%d ",p[i].Y);
    }
//	system("pause");
	return 0;
}