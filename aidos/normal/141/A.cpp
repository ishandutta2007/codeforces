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
    int a[30];
    for(int i=0; i<28; i++)
        a[i] = 0;
    string s, t;
    for(int i =0; i<2; i++){
        cin >> s;
        int n = s.size();
        for(int j=0; j<n; j++)
            a[s[j]-'A']++;
    }
    cin >> s;
    int n = s.size();
    for(int i = 0; i<n; i++)
        a[s[i]-'A'] --;
    for(int i=0; i<27; i++){
        if(a[i] != 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}