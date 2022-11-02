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
void f(string s){
    int n = s.size(), k = 0;
    for(int i = 0; i<n; i++)
        if(s[i] == '@') k = i;
    if( k == 0 || k == n-1) {
        cout << "NO";
        exit(0);
    }
    for(int i = 0; i<k; i++){
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'|| s[i] >='0' && s[i] <='9' || s[i] == '_'){
            continue;
        }
        cout << "NO";
        exit(0);
    }
    s[k] = '.';
    if(s[n-1] == '.'){
        cout << "NO";
        exit(0);
    }
    for(int i = k+1; i<n; i++){
        if(s[i] == '.'){
            if(s[i-1] == '.'){
                cout << "NO";
                exit(0);
            }
        }
        else if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'|| s[i] >='0' && s[i] <='9' || s[i] == '_'){
            continue;
        }
        else {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
    exit(0);
}
int main () {
    string s;
    cin >> s;
    int n = s.size(), k = 0, l = 0, t = 0, u = 0;
    for(int i = 0; i<n; i++)
        if(s[i] == '@') k++;
    if(k!=1) {
        cout << "NO";
        return 0;
    }
    k = 0;
    for(int i =0; i<n; i++)
        if(s[i] == '/') k++;
    if(k == 0) f(s);
    if(k != 1){
        cout << "NO";
        return 0;
    }
    for(int i = 0; i<n; i++)
        if(s[i] == '@') k = i;
        else if(s[i] == '/') l = i;
    if(k>l || k == 0 || l == n-1||l == k+1 || s[l-1] == '.'){
        cout << "NO";
        return 0;
    }
    for(int i = 0; i<k; i++){
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'|| s[i] >='0' && s[i] <='9' || s[i] == '_'){
            continue;
        }
        cout << "NO";
        return 0;
    }
    for(int i = l+1; i<n; i++){
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'|| s[i] >='0' && s[i] <='9' || s[i] == '_'){
            continue;
        }
        cout << "NO";
        return 0;
    }
    s[k] = '.';
    for(int i = k+1; i<l; i++){
        if(s[i] == '.'){
            if(s[i-1] == '.'){
                cout << "NO";
                return 0;
            }
        }
        else if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'|| s[i] >='0' && s[i] <='9' || s[i] == '_'){
            continue;
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}