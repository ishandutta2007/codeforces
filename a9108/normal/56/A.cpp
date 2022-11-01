#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define eps 1e-8
#define PB push_back
#define MP make_pair
using namespace std;
double pi=asin(1.0)*2;

set<string> a;

int main(){
    a.clear();
    a.insert("ABSINTH");
    a.insert("BEER");
    a.insert("BRANDY");
    a.insert("CHAMPAGNE");
    a.insert("GIN");
    a.insert("RUM");
    a.insert("SAKE");
    a.insert("TEQUILA");
    a.insert("VODKA");
    a.insert("WHISKEY");
    a.insert("WINE");
    int n,ans=0;
    char s[200];
    string ts;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int t;
        if (scanf("%d",&t)==1){
            if (t<18) ans++;
        }
        else {
            scanf("%s",s);
            ts=s;
            if (a.find(s)!=a.end()) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}