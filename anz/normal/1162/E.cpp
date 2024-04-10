#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector <int> a;
    int n;
    cin >> n;
    a.resize(n);
    for (int i=0;i<n;i++)
     cin >> a[i];
    
    sort(a.begin(),a.end());
    
    if(a[0]==a[n/2]) cout << "Bob";
    else cout << "Alice";
    
}