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
    int n;
    scanf("%d ",&n);
    for (int i=0;i<n;++i){
        scanf(" ");
        string s;
        getline(cin,s);
        int l=s.size();
        if (l>10){
            printf("%c%d%c\n",s[0],l-2,s[l-1]);
        }
        else printf("%s\n",s.c_str());
    }
    return 0;
}