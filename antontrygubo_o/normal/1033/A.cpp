#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double


int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int ax, ay, bx, by, cx, cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    if (bx<ax&&ax<cx) {cout<<"NO"; return 0;}
    if (cx<ax&&ax<bx) {cout<<"NO"; return 0;}    
    if (by<ay&&ay<cy) {cout<<"NO"; return 0;}
    if (cy<ay&&ay<by) {cout<<"NO"; return 0;}
    cout<<"YES";
    
}