//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
using namespace std;
int n,k,a[10005],res[12][10005],ans[12],cnt[12];
vector<int> v[24];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%1d",a+i),++cnt[a[i]];
    for(int i=0;i<=9;++i){
        if(cnt[i]>=k){
            printf("0\n");
            for(int i=1;i<=n;++i)printf("%d",a[i]);
            printf("\n");
            return 0;
        }
    }
    for(int i=0;i<=9;++i){
        for(int j=0;j<20;++j)v[j].clear();
        int o=k-cnt[i];
        for(int j=1;j<=n;++j){
            if(a[j]>i)v[(a[j]-i)*2].pb(j);
            if(a[j]<i)v[(i-a[j])*2+1].pb(j);
            res[i][j]=a[j];
        }
        for(int j=0;j<20;++j){
            if(!o) break;
            if(j&1)reverse(v[j].begin(),v[j].end());
            for(int l=0;l<v[j].size();++l){
                if(!o) break;
                --o;
                res[i][v[j][l]]=i;
                ans[i]+=(j>>1);
            }
        }
    }
    for(int i=1;i<=9;++i){
        if(ans[i]>ans[0]) continue;
        if(ans[i]<ans[0]){
            ans[0]=ans[i];
            for(int j=1;j<=n;++j)res[0][j]=res[i][j];
            continue;
        }
        bool ok=0;
        for(int j=1;j<=n;++j){
            if(res[0][j]!=res[i][j]){
                if(res[0][j]>res[i][j])ok=1;
                break;
            }
        }
        if(ok){
            for(int j=1;j<=n;++j)res[0][j]=res[i][j];
        }
    }
    printf("%d\n",ans[0]);
    for(int i=1;i<=n;++i)printf("%d",res[0][i]);
    printf("\n"); 
//	system("pause");
	return 0;
}