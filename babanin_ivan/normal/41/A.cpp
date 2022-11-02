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

string s1;
string s2;

void no(){
    cout<<"NO"<<endl;
    exit(0);
}

void yes(){
    cout<<"YES"<<endl;
    exit(0);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    getline(cin,s1,'\n');
    scanf(" ");
    getline(cin,s2,'\n');
    if (s1.length()!=s2.length())
        no();
    int l=0;
    int r=s2.size()-1;
    while (r>=0){
        if (s1[l]!=s2[r])
            no();
        ++l;
        --r;
    }
    yes();
    return 0;
}