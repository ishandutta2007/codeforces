#include <bits/stdc++.h>
using namespace std;

int main(){
    int ntest;
    cin >> ntest;
    while (ntest--){
        char s[1005];
        for (int i=0; i<=1004; i++){
            s[i]='\0';
        }
        cin >> s;
        sort(s, s+strlen(s));
        if (s[0]==s[strlen(s)-1]) cout << -1 << endl;
        else cout << s << endl;
    }
}