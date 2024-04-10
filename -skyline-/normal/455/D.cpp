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
#define pb(x)   push_back(x)
#define pf(x)   push_front(x)
#define mb      pop_back()
#define mf      pop_front()
using namespace std;
int n,a[100005],u[323][100005],num[100005],lans,t,l,r,x,y,k,ll,rr;
deque<int> q[323];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            num[i]=i/320;
            scanf("%d",a+i);
            q[num[i]].pb(a[i]);
            u[num[i]][a[i]]++;
    }
    scanf("%d",&t);
    while(t--){
               scanf("%d %d %d",&x,&l,&r);
               l=(l+lans-1)%n;
               r=(r+lans-1)%n;
               if(l>r) swap(l,r);            
               ll=l%320;
               rr=r%320;
               if(x==1){
                        if(l==r) continue;
                        k=q[num[r]][rr];
                        q[num[r]].erase(q[num[r]].begin()+rr);
                        q[num[l]].insert(q[num[l]].begin()+ll,k);
                        u[num[r]][k]--;
                        u[num[l]][k]++;
                        for(int i=num[l];i<num[r];i++){
                                q[i+1].pf(q[i].back());
                                u[i+1][q[i].back()]++;
                                u[i][q[i].back()]--;
                                q[i].mb;
                        }
               }
               else{
                    scanf("%d",&k);
                    k=(k+lans-1)%n+1;
                    lans=0;
                    if(num[l]==num[r]) for(int i=ll;i<=rr;i++)lans+=q[num[l]][i]==k;
                    else{
                         for(int i=ll;i<q[num[l]].size();i++)lans+=q[num[l]][i]==k;
                         for(int i=num[l]+1;i<num[r];i++)lans+=u[i][k];
                         for(int i=0;i<=rr;i++)lans+=q[num[r]][i]==k;
                    }
                    printf("%d\n",lans);
               }
    }           
	//system("pause");
	return 0;
}