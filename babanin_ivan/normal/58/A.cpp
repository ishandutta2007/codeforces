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
    string hello="hello";
    string s;
    getline(cin,s);
    int i=0;
    int k=0;
    while (k<5 && i<s.size()){
        while (s[i]!=hello[k] && i<s.size())
            ++i;
        if (i==s.size()){
            printf("NO\n");
            return 0;
        }
        ++k;
        ++i;
    }
    if (k==5)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}