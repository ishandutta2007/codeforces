#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.length();
    int dec;
    int e;
    for(int i = 0; i<n; i++){
        if(s[i] == '.'){
            dec = i;
        }
        if(s[i] == 'e'){
            e = i;
            break;
        }
    }
    string num = s.substr(0, e);
    double act =::atof(num.c_str());
    string s1 = s.substr(0, dec);
    string s2 = s.substr(dec+1,e - dec -1);
    string s3 = s.substr(e+1, n-1-e);
    int val = atoi(s3.c_str());
    if(act == static_cast<int>(act) && val == 0){
        cout << static_cast<int>(act);
        return 0;
    }
    if(val<s2.length()){
        string s4 = s2.substr(0, val);
        string s5 = s2.substr(val, s2.length() - val);
       // cout <<s4 << " " <<s5<< endl;
        cout << (s1 + s4 + "." + s5)<< endl;
    }
    else if(val == s2.length()){
        cout << (s1 + s2);
    }
    else{
            string s4 = "";
        for(int i = 0; i<val - s2.length(); i++){
            s4 = s4+ "0";
        }
        cout << (s1+s2+ s4);
    }
    return 0;
}