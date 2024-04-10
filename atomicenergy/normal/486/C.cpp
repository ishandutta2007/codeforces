#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>

#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m,n;
    cin >> m >> n;
    char a[100000];
    cin >> a;
    if(n*2>m)
        n=m+1-n;
    n--;
    int counter=0;
    int moves=0;
    int d;
    vector<int> v;
    for(int i=0; 2*i<m-1; i++){
        if(a[i]!=a[m-1-i]){
            v.push_back(i);
        }
        d=a[i]-a[m-1-i];
        if(d<0)
            d*=-1;
        if(d>13)
            d=26-d;
        counter +=d;
    }
    if(v.size()==0){
        moves=0;
    }
    else if(n<v[0]){
        moves=v[v.size()-1]-n;
    }
    else if (n>v[v.size()-1]){
        moves=n-v[0];
    }
    else{
        if(n-v[0]<v[v.size()-1]-n){
            moves=v[v.size()-1]+n-v[0]-v[0];
        }
        else{
            moves=v[v.size()-1]+v[v.size()-1]-n-v[0];
        }
    }
    cout << moves + counter << endl;

}