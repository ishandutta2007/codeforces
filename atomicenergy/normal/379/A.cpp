/*
ID: zachary12
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#define go(a,b) for(int a=0; a<b; a++)
using namespace std;


int main()
{
    int n,m;
    cin >> n >> m;
    int total=0;
    while(n>=m){
        n-=m-1;
        total+=m;
    }
    cout << total+n;
}