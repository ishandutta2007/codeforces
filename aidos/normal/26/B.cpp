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
    int n = s.length(), t=0, k=0, m = 0;
    for(int i = 0; i<n; i++)
        if(s[i]=='(') k++;
        else {
            if(k){
                k--;
                t+=2;
            }
            else {
                m+=t;
                t = 0;
                k = 0;
            } 
        }
    cout << m+t;
    return 0;
}