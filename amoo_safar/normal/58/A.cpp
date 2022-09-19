#include<iostream>
using namespace std;
int main(){
    string a,b="hello";
    cin >> a;
    long long i=0, j=0;
    while((i<a.size()) and (5 > j)){
        if(a[i] == b[j]) j++;
        i++;
    }
    if(j==5) cout << "YES";
    else cout << "NO";
}