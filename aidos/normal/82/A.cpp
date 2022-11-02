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
string s[] = {
    "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"
};
int main () {
    int n, a, b, c, cur = 1;
    cin >> n;
    n--;
    while(1){
        if(cur * 5 > n){
            int x = n/cur;
            cout << s[x];
            return 0;
        }
        n-=cur*5;
        cur*=2;
    }
    return 0;
}