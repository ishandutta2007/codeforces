#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,k;

int main()
{
	cin>>n>>k;
	cout<<(n*2-1)/k+1+(n*5-1)/k+1+(n*8-1)/k+1<<endl; 
    return 0;
}