#include <bits/stdc++.h>

using namespace std;

int main() 
{
int n,pos, l, r;
cin>>n>>pos>>l>>r;
int time = 0;
if ((l==1)&&(r==n)) {cout<<0; return 0;}
if (l==1) {cout<<fabs(pos-r)+1; return 0;}
if (r==n) {cout<<fabs(pos-l) + 1; return 0;}

if (pos<l)
{
    time = r-pos;
}
else if (pos>r)
{
    time = pos-l;
}
else 
{
    time = r-l + min(pos-l, r-pos);
}

cout<<time+2;

}