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

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s;
    getline(cin,s,'\n');
    bool f=false;
    n=s.size();
    for (int i=0;i<n;++i)
        if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]== 'U' || s[i]=='Y' ||
            s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]== 'u' || s[i]=='y')
            f=false;
        else if ((s[i]<='Z' && s[i]>='A')|| (s[i]>='a' && s[i]<='z'))
                f=true;
    if (!f)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}