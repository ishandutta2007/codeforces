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
    int n = 0, k = 0;
    string s;
    cin >> s;
    for(int i = 0; i<s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z') n++;
        else k++;
    }
    if(k > n){
        for(int i = 0; i<s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z') cout << (char)(s[i] - 'a' + 'A');
            else cout << s[i];
        }
    }
    else {
        for(int i = 0; i<s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z') cout << (char)(s[i] - 'A' + 'a');
            else cout << s[i];
        }
    }
    return 0;
}