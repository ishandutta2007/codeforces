#include <bits/stdc++.h>

using namespace std;

string days[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    int idx1 = 0, idx2 = 0;
    for(int i  = 0; i<7; i++){
        if(days[i] == a){
            idx1 = i;
        }
    }
    for(int i = 0; i<7; i++){
        if(days[i] == b){
            idx2 = i;
        }
    }
    if((idx1+31)%7 != idx2 && (idx1+28)%7  != idx2 && (idx1+30)%7 != idx2){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}