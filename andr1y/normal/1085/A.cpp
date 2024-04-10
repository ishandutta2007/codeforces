#include<bits/stdc++.h>
using namespace std;
#define int long long
main(){
    string s;
    cin >> s;
    string r = "";
    int obrab = 0;
    int cnt = s.length()/2-1;
    if(s.length()%2) ++cnt;
    int offset = 0;
    bool right = false;
    while(obrab!=s.length()){
        if(right){ if(cnt+offset<s.length()) r+= s[cnt+offset];}
        else     { if(cnt-offset>=0)         r+= s[cnt-offset];}
        if(!right) offset++;
        right = !right;
        obrab++;
    }
    cout << r;
}