#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

const int maxn = 2e5;

typedef long long ll;
typedef double db;

string s;
pair < int, int > a[maxn];
int  uk;

bool less1(pair < int, int > a, pair < int, int > b){
    return (a.first > b.first) || (a.first == b.first && a.second < b.second);
}


int main(){
   int n, i;
    int last;
    cin >> s;
    n = s.length();
    forn(i, n){
        a[uk].second = i;
        a[uk++].first = s[i] - 'a';
    }
    sort(a, a + n, less1);
    last = -1;
    forn(i, n)
        if (a[i].second > last){
            printf("%c", (char) a[i].first + 'a');
            last = a[i].second;
        }
    


    return 0;

}