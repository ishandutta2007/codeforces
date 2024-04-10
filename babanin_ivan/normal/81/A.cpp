#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define pb push_back

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    getline(cin,s);
    vector <char > ans;
    for (int i=0;i<s.size();++i)
        if (!(ans.size()>0 && ans[ans.size()-1]==s[i]))
            ans.pb(s[i]);
        else if (ans.size()>0)
                ans.pop_back();
    for (int i=0;i<ans.size();++i)
        printf("%c",ans[i]);
}