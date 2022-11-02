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
const string roman[13]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
const int arab[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};

string toroman(int64 x){    
    string res;
    res.clear();
    for (int i=12;i>=0;--i)
        while (x>=arab[i]){
            res+=roman[i];
            x-=arab[i];
        }
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int64 a=0;
    int64 b=0;
    string s;
    getline(cin,s);
    int j=0;
    while (s[j]!=' '){
        a=a*10+s[j]-'0';
        ++j;
    }
    ++j;
    bool f=false;
    
    if (s[j]=='R')
        f=true;
    else {
        while (j<s.size()){
            b=b*10+s[j]-'0';
            ++j;
        }
    }
    int64 c,d,e;
    c=0;
    getline(cin,s,'\n');
    for (int i=0;i<s.size();++i){
        c=c*a;
        if (s[i]>='0' && s[i]<='9')
            c+=s[i]-'0';
        else c+=s[i]-'A'+10;
    }

    if (!f){
        vector <int64> ans;
        ans.clear();
        if (c==0)
            printf("0\n");
        while (c){
            ans.pb(c % b);
            c=c/b;
        }
        
        for (int i=ans.size()-1;i>=0;--i){
            if (ans[i]>=0 && ans[i]<=9)
                printf("%d",ans[i]);
            else printf("%c",char(ans[i]-10+'A'));
        }
    }
    else {
        string ans=toroman(c);
        printf("%s\n",ans.c_str());
    }
    return 0;
}