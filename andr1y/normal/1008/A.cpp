#include <bits/stdc++.h>
using namespace std;
map<char,bool>v;
int main (){
    v['a']=v['i']=v['o']=v['e']=v['u']=1;
    string s; cin>>s;
    bool ch=1;
    for (int i=0; i<s.size()-1 ; i++){
        if (s[i]=='n') continue;
        if (!v[s[i]] && !v[s[i+1]]) ch=0;
    }
    if (!v[s.back()] && s.back() != 'n') ch=0;
    if (ch)cout<<"YES";
    else cout<<"NO";
}