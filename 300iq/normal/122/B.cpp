#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int main(){
    string s;
    int counter4 = 0, counter7 = 0;
    cin >> s;
    if(s.find("4") != string::npos){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '4'){
                counter4++;
            }
        }
    }
    if(s.find("7") != string::npos){
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '7') {
                counter7++;
            }
        }
    }
    if(counter4 != 0 || counter7 != 0){
        if(counter4 >= counter7){
            cout << 4;
        }
        else{
            cout << 7;
        }
    }
    else{
        cout << -1;
    }
}