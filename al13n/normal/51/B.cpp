#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <string.h>
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
#include <limits>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define forv(i,v) forn(i,(int)v.size())
#define time asdtime
#define pb push_back
#define lng long long
#define mp make_pair
#define iinf 1000000000
#define prev asdprev
#define next asdnext
#define all(v) v.begin(),v.end()

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    string s;
    string t;
    while(cin>>t)
        s+=t;
    vector<int> st;
    vector<int> res;
    for(int i=0;i<s.length();++i){
        if(s.substr(i,strlen("<table>"))=="<table>")
            st.pb(0);
        else if(s.substr(i,strlen("</table>"))=="</table>"){
            res.pb(st.back());
            st.pop_back();
        }else if(s.substr(i,strlen("<td>"))=="<td>")
            ++st.back();
    }
    sort(all(res));
    forv(i,res)
        cout<<res[i]<<' ';

    return 0;
}