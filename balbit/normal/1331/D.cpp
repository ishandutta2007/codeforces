#include <iostream>
using namespace std;
 
signed main(){
    string s; cin>>s;
    string mo = "13579BDF";
    char c = s[s.length()-1];
    for (char x : mo) {
        if (x == c) {cout<<1<<endl; return 0;}
    }
    cout<<0<<endl;
}