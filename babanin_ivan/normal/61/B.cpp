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

void norm(string &s){
    string res;
    res.clear();
    for (int i=0;i<s.size();++i){
        if (s[i]=='-' || s[i]==';' || s[i]=='_')
            continue;
        res.push_back(tolower(s[i]));
    }
    s=res;
}

string s[5];
int n;
int k=0;
string perest[15];
vector<int > tek;
bool used[10];

void pereb(int pos){
    if (pos==3){
        ++k;
        for (int i=0;i<3;++i)
            perest[k-1]+=s[tek[i]];
        return ;
    }
    for (int i=0;i<3;++i)
        if (!used[i]){
            tek.pb(i);
            used[i]=true;
            pereb(pos+1);
            used[i]=false;
            tek.pop_back();
        }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    for (int i=0;i<3;++i){
        getline(cin,s[i]);
        norm(s[i]);
    }
    pereb(0);

    scanf(" %d ",&n);
    for (int i=0;i<n;++i){
        string ans;
        getline(cin,ans);
        norm(ans);
        bool f=false;
        for (int j=0;j<k;++j)
            if (ans==perest[j])
                f=true;
        if (f)
            printf("ACC\n");
        else printf("WA\n");
    }
    return 0;
}