#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int i = 2;
    while(i < s.size()){
        if(((int) s[i-2] + (int) s[i-1] - 2 * (int) 'A') %26 != (int) s[i] - (int) 'A') { cout<<"NO\n"; return 0;}
        i++;
    }
    cout<<"YES\n";
}