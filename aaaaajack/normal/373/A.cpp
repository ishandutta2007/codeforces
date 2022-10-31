#include <vector>
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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define lli long long int
#define li long int
#define S(a) a.size()
#define pb(vector, value) (vector).push_back((value))
#define Max(a,b) (a)>(b)?(a):(b)
#define Min(a,b) (a)<(b)?(a):(b)
#define poo 1000000009
#define noo -1000000009

using namespace std;

int main()
{
    int k, i, j;
    int a[5][5];
    int t[12]= {0};
    cin>>k;
    for(i=0;i<4;++i){
                     string s;
                     cin>>s;
                     for(j=0;j<4;++j){
                                      if(s[j]!='.')
                                      ++t[(int)(s[j] - '1')];
                     }
    }
    for(i=0;i<12;++i){
                      if(t[i]>2*k)
                      break;
    }
    if(i!=12)
    cout<<"NO";
    else
    cout<<"YES";
}