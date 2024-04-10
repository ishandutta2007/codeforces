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
#include <map>
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
vector <int> a, b, c;
int n, k;
cin >> n;
for(int i=0; i<n; i++){
    cin >> k;
    if(k<0) a.pb(k);
    else if(k==0) b.pb(k);
    else c.pb(k);
}
if(c.size()==0){
    c.pb(*(a.begin()));
    a.erase(a.begin());
    c.pb(*(a.begin()));
    a.erase(a.begin());
}
if(a.size()%2==0){
    b.pb(*(a.begin()));
    a.erase(a.begin());       
}
cout << a.size() << " ";
for(vector <int> ::iterator it = a.begin(); it!= a.end(); it++)
    cout << *it << " ";
cout << endl << c.size() << " ";

for(vector <int> :: iterator it = c.begin(); it!= c.end(); it++)
    cout << *it << " ";

cout << endl << b.size() << " ";
for(vector <int> :: iterator it = b.begin(); it!= b.end(); it++)
    cout << *it << " ";
return 0;
}