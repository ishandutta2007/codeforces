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

bool end(char c){
    if (c=='.' || c=='?' || c=='!')
        return true;
    else return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d ",&n);
    string s;
    getline(cin,s);
    int l=s.size();
    int ans=0;
    int teksz=n;
    int i,j;
    i=0;
    while (i<l){
        j=i;
        while (j<l && !end(s[j]))
            ++j;
        if (j-i+1>n){
            cout<<"Impossible\n";
            return 0;
        }
        if (teksz+j-i+2<=n)
            teksz+=j-i+1+1;
        else {
            ++ans;
            teksz=j-i+1;
        }
        i=j+2;
    }
    cout<<ans<<endl;
    return 0;
}