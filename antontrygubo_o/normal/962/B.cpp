#include <bits/stdc++.h>

using namespace std;
int counter = 0;

void f (int sits, int &a, int &b)
{
    if (a<b) swap(a, b);
    int g1 = min(a, (sits+1)/2);
    int g2 = min(b, sits/2);
    a-=g1;
    b-=g2;
    counter+=(g1+g2);
}


int main() {
int n, a, b;
cin>>n>>a>>b;
string s;
cin>>s;
vector<int> sit;
int j = 0;
for (int i = 0; i<n; i++)
{
    if (s[i]=='*' && j!=0) sit.push_back(j);
    if (s[i]=='*') j = 0;
    else j++;
}
if (j!=0) sit.push_back(j);
for (int i = 0; i<sit.size(); i++) {f(sit[i], a, b);}
cout<<counter;
}