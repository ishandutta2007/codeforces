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

string pref;
int n;
string a[200];

bool is_pref(string pref,string x){
    if (pref.size()>x.size())
        return false;
    bool f=true;
    for (int i=0;i<pref.size();++i)
        if (pref[i]!=x[i])
            f=false;
    return f;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    getline(cin,pref,'\n');
    scanf(" %d ",&n);
    for (int i=0;i<n;++i){
        scanf(" ");
        getline(cin,a[i]);
    }
    sort(a,a+n);
    for (int i=0;i<n;++i)
        if (is_pref(pref,a[i])){
            printf("%s\n",a[i].c_str());
            return 0;
        }
    printf("%s\n",pref.c_str());
    return 0;
}