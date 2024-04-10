#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define int64 long long       
#define ld long double

const int inf=2000000000;

int a[5];

bool won1(){
    if (a[0]==0 && a[1]==2 && a[2]==2)
        return true;
    if (a[0]==1 && a[1]==0 && a[2]==0)
        return true;
    if (a[0]==2 && a[1]==1 && a[2]==1)
        return true;
    return false;
}

bool won2(){
    if (a[1]==0 && a[0]==2 && a[2]==2)
        return true;
    if (a[1]==1 && a[0]==0 && a[2]==0)
        return true;
    if (a[1]==2 && a[0]==1 && a[2]==1)
        return true;
    return false;
}
bool won3(){
    if (a[2]==2 && a[1]==1 && a[0]==1)
        return true;
    if (a[2]==0 && a[1]==2 && a[0]==2)
        return true;
    if (a[2]==1 && a[1]==0 && a[0]==0)
        return true;
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s;
    for (int i=0;i<3;++i){
        getline(cin,s,'\n');
        if (s=="rock")
            a[i]=0;
        else if (s=="paper")
            a[i]=1;
        else a[i]=2;
    }
    if (won1()){
        cout<<"F"<<endl;
        return 0;
    }
    if (won2()){
        cout<<"M"<<endl;
        return 0;
    }
    if (won3()){
        cout<<"S"<<endl;
        return 0;
    }
    cout<<"?"<<endl;
    return 0;
}