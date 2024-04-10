#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

const int maxn = 110;
int n, m;
int a[maxn][maxn];
int b[maxn];
int c[maxn];
int useb[maxn];
int usec[maxn];

void conv(){
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));    
    forn(i, n)
        forn(j, m){
            b[i] += a[i][j];
            c[j] += a[i][j];
        }   
}


int main(){
    bool check;
    cin >> n >> m;
    forn(i, n)
        forn(j, m)
            cin >> a[i][j];
        
    conv();
    check = 1;
    //int it = 0;
    while(check){
      //  it++; 
        //cerr << "it: " << it << endl;
        forn(i, n)
            if (b[i] < 0){
    useb[i] = useb[i] ^ 1;
    forn(j, m)
        a[i][j] *= -1;
            }
        conv();
        forn(j, m)
            if (c[j] < 0){
    usec[j] = usec[j] ^ 1;
    forn(i, n)
        a[i][j] *= -1;
            }  
        
        conv();
        check = 0;
        forn(i, n)
            if(b[i] < 0)
    check = 1;
        forn(j, m)
            if(c[j] < 0)
    check = 1;
    }
    int cnt1 = 0, cnt2 = 0;
    forn(i, n)
        if(useb[i])
            cnt1++;
    forn(j, m)
        if(usec[j])
            cnt2++;
    cout << cnt1 << " ";
    
    forn(i, n)
        if (useb[i])
            cout << i + 1 << " ";
        
    cout << endl << cnt2 << " ";
    
    forn(j, m)
        if (usec[j])
            cout << j + 1 << " ";
        
        
    
    return 0;
}