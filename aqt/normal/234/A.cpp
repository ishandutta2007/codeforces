#include <bits/stdc++.h>

using namespace std;

string s;
int N;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> N;
    cin >> s;
    for(int i = N/2-1; i>=0; i--){
        if(s[i] == 'R' && s[i+N/2] == 'L'){
            cout << i+N/2+1 << " " << i+1 << endl;
        }
        else{
            cout << i+1 << " " << i+N/2+1 << endl;
        }
    }
}