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
int main () {
    string s;
    cin >> s;
    for(int i = s.size(); i>0;i--){
        set < string > S;
        for(int j = 0; j+i<=s.size(); j++){
            S.insert(s.substr(j, i));
        }
        if(S.size() != s.size()-i+1){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0;
    return 0;
}