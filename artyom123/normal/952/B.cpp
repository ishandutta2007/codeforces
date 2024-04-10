#include <bits/stdc++.h>
using namespace std;
int main(){
    int f=0;
    for(int i=0;i<10;i++){
        cout << i << '\n' << flush;
        string s;
        getline(cin, s);
        if(s=="cool"||s=="not bad"||s=="great"||s=="don't think so"||s=="don't touch me"){
            cout << "normal";
            return 0;
        }
        else if(s!="no"){
            cout << "grumpy";
            return 0;
        }
        else f++;
        if(f>3){
            cout << "normal";
            return 0;
        }
    }
}