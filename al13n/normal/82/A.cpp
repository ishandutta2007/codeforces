#pragma comment (linker, "/STACK:90000000")
#include <string>
#include <memory.h>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <utility>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-9
#define iinf 1000000000
#define SQ(a) ((a)*(a))

queue<pair<string,lng> > qu;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    string asd[]={ "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    forn(i,5)
        qu.push(mp(asd[i],1));

    int N;
    cin>>N;

    while(true){
        if(qu.front().second>=N){
            cout<<qu.front().first;
            return 0;
        }
        N-=qu.front().second;
        qu.push(mp(qu.front().first,qu.front().second*2));
        qu.pop();
    }

    return 0;
}