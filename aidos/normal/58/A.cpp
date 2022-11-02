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
#define pll pair <long long,long long>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define MAXN 1000000
#define INF 1000000000
using namespace std;
string t = "hello"; 
int main () {
    string s;
    cin >> s;
    int n = s.size(), z=0;
    for(int i=0; i<5; i++){
        bool ok = 0;
        for(int j = z; j<n; j++){
            if(s[j] == t[i]){
                ok = 1;
                z = j+1;
                break;
            }
        }
        if(!ok){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}