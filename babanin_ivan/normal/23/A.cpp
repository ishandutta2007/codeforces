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
const int hash=997;

string s;
int n;
int64 step[300];
int64 prec[300];
vector<pair<int ,int64> > a;

int64 gethash(int l,int r){
    if (l==0)
        return prec[r];
    return prec[r]-prec[l-1]*step[r-l+1];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    getline(cin,s,'\n');
    n=s.size();
    prec[0]=s[0];
    for (int i=1;i<n;++i)
        prec[i]=prec[i-1]*hash+s[i];
    step[0]=1;
    for (int i=1;i<200;++i)
        step[i]=step[i-1]*hash;
    for (int r=0;r<n;++r)
        for (int l=0;l<=r;++l)
            a.pb(mp(r-l+1,gethash(l,r)));
    sort(a.begin(),a.end());
    int m=a.size();
    int ans=0;
    int j;
    for (int i=0;i<m-1;++i)
        if (a[i]==a[i+1])
            ans=max(ans,a[i].first);
    cout<<ans<<endl;
    return 0;
}