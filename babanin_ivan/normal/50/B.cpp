#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define int64 long long       
#define ld long double

const int inf=2000000000;

int64 b[2000];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m;
    string s;
    getline(cin,s,'\n');
    n=s.size();
    for (int i=0;i<n;++i)
        ++b[s[i]];
    int64 ans=0;
    for (int i=0;i<n;++i){
        ans+=b[s[i]];
    }
    cout<<ans<<endl;
}