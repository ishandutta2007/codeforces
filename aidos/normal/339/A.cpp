#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <map>
using namespace std;
int main () {
    string s, t = "";
    cin >> s;
    int x = s.size();
    vector < string > v;
    for(int i = 0; i<x; i++){
        if(s[i]=='+') {
            v.push_back(t);
            t = "";
        }    
        else t = t + s[i];
    }    
    if(t!="") v.push_back(t);
    sort(v.begin(), v.end());
    x=v.size()-1;
    for(int i = 0; i<x; i++){
        if(v[i] != "") {
            cout << v[i] << '+';
        }
    }
    cout << v[x];
	return 0;
}