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

int n;

bool alk(string s){
    if (s=="ABSINTH" ||  s=="BEER" || s=="BRANDY"|| s=="CHAMPAGNE" || s=="GIN" || s=="RUM" || s=="SAKE" || s=="TEQUILA" ||
        s=="VODKA" || s=="WHISKEY" || s=="WINE")
        return true;
    else return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d ",&n);
    int ans=0;
    for (int i=0;i<n;++i){
        string s;
        s.clear();
        getline(cin,s,'\n');
        if ('0'<=s[0] && s[0]<='9'){
            int k=0;
            for (int j=0;j<s.size();++j)
                k=k*10+s[j]-'0';
            if (k<18)
                ++ans;
        }
        else {
            if (alk(s))
                ++ans;
        }
        scanf(" ");
    }
    cout<<ans<<endl;
    return 0;
}