#include <bits/stdc++.h>
using namespace std;

string s;

bool pal(string s) {
    for(int i=0;i<s.size()/2;++i)
        if(s[i]!=s[s.size()-i-1])
            return 0;
    return 1;
}

int main() {
    cin>>s;
    for(int i=0;i<=s.size();++i) for(char c='a';c<='z';++c) {
        string b = s; b.insert(b.begin()+i, c);
        if(pal(b)) return cout<<b<<'\n', 0;
    }
    puts("NA");
}