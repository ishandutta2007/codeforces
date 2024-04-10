#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
bool fs(string s){
    int n = s.size();
    if(n<5) return false;
    if(s.substr(0, 5) == "miao.") return true;
    return false;    
}
bool ss(string s){
    int n = s.size();
    if(n<5) return false;
    if(s.substr(n-5, 5) == "lala.") return true;
    return false;
}
int main () {   
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for(int i = 0; i<n; i++){
        getline(cin, s);
        bool a = fs(s), b = ss(s);
        if(!a && b) cout << "Freda's\n";
        else if(a && !b)  cout << "Rainbow's\n";
        else cout << "OMG>.< I don't know!\n";
    }
    return 0;
}