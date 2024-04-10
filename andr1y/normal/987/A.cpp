#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string a[6] = {"Power\n", "Time\n", "Space\n", "Soul\n", "Reality\n", "Mind\n"};
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s== "purple") a[0]=""; 
        else if(s== "green") a[1]=""; 
        else if(s== "blue") a[2]=""; 
        else if(s== "orange") a[3]=""; 
        else if(s== "red") a[4]=""; 
        else if(s== "yellow") a[5]=""; 
    }
    cout << 6-n << endl;
    for(int i=0;i<6;i++) cout<<a[i];
}