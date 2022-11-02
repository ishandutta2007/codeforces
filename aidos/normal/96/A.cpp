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
int main () {
    string s;
    cin >> s;
    int n = s.size(), k = 0, l = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '0'){
            k++;
            l = 0;
        }
        else {
            l++;
            k = 0;
        }
        if(k == 7||l == 7){
            cout<< "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}