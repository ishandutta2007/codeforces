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
#ifdef __ASD__
#include <windows.h>
#endif
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
#define linf 1000000000000000000LL
#define left asdleft
#define prev asdprev
#define eps 1e-8
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
const double dinf = 1e200;
void mytimer(string task){
#ifdef __ASD__
    static LARGE_INTEGER prev;  LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);   if(task!="")        cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl; prev=cur;
#endif
}
void ext(int c){
#ifdef __ASD__
    exit(c);
#endif
}

bool end(string s,string e){
    return s.length()>=e.length()&&s.substr(s.length()-e.length())==e;
}

bool read(bool &sex,int &type){
    string s;
    if(!(cin>>s))
        return false;
    if(end(s,"lios"))
        sex=false,type=0;
    else if(end(s,"liala"))
        sex=true,type=0;
    else if(end(s,"etr"))
        sex=false,type=1;
    else if(end(s,"etra"))
        sex=true,type=1;
    else if(end(s,"initis"))
        sex=false,type=2;
    else if(end(s,"inites"))
        sex=true,type=2;
    else
        type=-1;
    return true;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    bool sex;
    int type;
    vector<int> types;
    bool was1=false,was2=false;
    while(read(sex,type)){
        if(type==-1){
            cout<<"NO";
            return 0;
        }
        types.pb(type);
        if(sex)
            was1=true;
        else
            was2=true;
    }
    if(types.size()==1){
        cout<<"YES";
        return 0;
    }
    if(was1&&was2){
        cout<<"NO";
        return 0;
    }
    while(types.size()&&types.back()==2)
        types.pop_back();
    reverse(all(types));
    while(types.size()&&types.back()==0)
        types.pop_back();
    if(types.size()==1&&types.back()==1)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}