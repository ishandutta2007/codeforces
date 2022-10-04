#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int w1,h1,w2,h2;

int main()
{
    cin>>w1>>h1>>w2>>h2;
    cout<<2*h1+w1+2+2*h2+w2+2+w1-w2<<endl;
    return 0;
}