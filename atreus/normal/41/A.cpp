#include<bits/stdc++.h>

using namespace std;

string c;

string rev(string s){
    int n = s.length();
    c = s;
    for (int i = 0; i < s.length(); i++){
        c[i] = s[n - i - 1];
    }
    return c;
}
int main (){
    string s, a;
    cin >> s >> a;
    if (rev(s) == a)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}