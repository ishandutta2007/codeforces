#include <vector>
#include <cstring>
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
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <complex>
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define left asdleft



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n;
    int l=0;
    int p=n;
    int res=0;
    string s;
    while(cin>>s){
        l+=s.length()+1;
        char c=s[s.length()-1];
        if(c=='.'||c=='?'||c=='!'){
            l--;
            if(l>n){
                cout<<"Impossible";
                return -0;
            }
            if(p+l+1>n){
                p=l;
                ++res;
            }else{
                p+=l+1;
            }
            l=0;
        }
    }
    cout<<res;

    return 0;
}