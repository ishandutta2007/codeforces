#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    int h, m, s, t1, t2;
    cin>>h>>m>>s>>t1>>t2;
    h*=5;
    t1*=5; t2*=5;
    h%=60;
    t1%=60;
    t2%=60;
    int move = t1;
    h = (h+60-move)%60;
    m = (m+60-move)%60;
    s = (s+60-move)%60;
    t1 = (t1+60-move)%60;
    t2 = (t2+60-move)%60;
    if (h<t2&&m<t2&&s<t2) {cout<<"YES"; return 0;}
    move = t2;
    h = (h+60-move)%60;
    m = (m+60-move)%60;
    s = (s+60-move)%60;
    t1 = (t1+60-move)%60;
    t2 = (t2+60-move)%60;
    if (h<t1&&m<t1&&s<t1) {cout<<"YES"; return 0;}
    cout<<"NO";
    
}