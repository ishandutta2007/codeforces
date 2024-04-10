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

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s;
    getline(cin,s);
    int n=s.size();
    int a[3];
    a[0]=a[1]=0;
    for (int i=0;i<n;++i){
        a[0]+=islower(s[i])/2;
        a[1]+=isupper(s[i]);
    }
    if (a[1]>a[0]){
        for (int i=0;i<n;++i)
            s[i]=toupper(s[i]);
    }
    else {
        for (int i=0;i<n;++i)
            s[i]=tolower(s[i]);
    }
    printf("%s",s.c_str());
    return 0;
}